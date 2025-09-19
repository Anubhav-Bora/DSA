import { getAutomationRoof, RoofOffsetMode } from "@abs/automation-roof";
import {
    CustomGuardRail,
    CustomGuardRailMetadata,
    DeselectMap,
    GuardRail,
    GuardRailCorner,
    GuardRailMetadata,
    MoveBySelector,
    MoveToSelector,
    PlanId,
    PlanRuleset,
    Point3D,
    ProductInstanceUnit,
    Railing,
    RailingCopyData,
    RailingsSelector,
    RailingsSelectorType,
    Roof,
    Roofs,
    SelectionMode,
    Vector3D,
} from "../../../type";
import { createProductInstance } from "../../Articles";
import { createGuardRailCornerId } from "../../ids";
import { projectPointOnRoofs } from "../../Roofs";
import { GuardRailAdditionSlot } from "../AdditionSlot";
import { isCustomGuardRail, isStandardGuardRail } from "../helpers";
import { createGuardRailMetadata, isCustomGuardRailMetadata } from "../helpers/createGuardRailMetadata";
import { GuardRailMutator } from "./GuardRailMutator";
import { GuardRailsMutator } from "./GuardRailsMutator";

interface IGuardRailCreator {
    addCorners(corners: GuardRailCorner[]): IGuardRailCreator;
    done(roofs?: readonly Roof[]): RailingMutator;
}
type GuardRailCreatorFactory = (mutator: RailingMutator) => IGuardRailCreator;

export class RailingMutator {
    constructor(
        private readonly railing: Railing,
        private readonly guardRailCreatorFactory: GuardRailCreatorFactory,
    ) {}

    public mutateGuardRails(fn: (mutator: GuardRailsMutator) => GuardRailsMutator): RailingMutator {
        const nextGuardRails = fn(new GuardRailsMutator(this.railing.guardRails)).done();
        if (nextGuardRails === this.railing.guardRails) return this;

        const withoutUndefined = nextGuardRails.filter((guardRail) => guardRail !== undefined) as GuardRail[];
        const lengthIsEqual = withoutUndefined.length === this.railing.guardRails.length;
        if (withoutUndefined.reduce(eachEqual(this.railing.guardRails), lengthIsEqual)) {
            return this;
        }

        return new RailingMutator(
            {
                ...this.railing,
                guardRails: withoutUndefined,
            },
            this.guardRailCreatorFactory,
        );
    }

    public deselectAll(deselectMap?: DeselectMap): RailingMutator {
        return this.mutateGuardRails((guardRailsMutator) =>
            guardRailsMutator.eachItem((itemMutator) => itemMutator.deselectAll(deselectMap)),
        );
    }

    public updateSelection(selector: RailingsSelector, mode: SelectionMode = SelectionMode.SELECT): RailingMutator {
        if (selector.type === RailingsSelectorType.RAILING) return this;

        const { railingId, guardRailIndex = -1 } = selector.address;
        if (railingId !== this.railing.id) return this;

        return this.mutateGuardRails((mutator) =>
            mutator.mutateItem(guardRailIndex, (itemMutator) => itemMutator.updateSelection(selector, mode)),
        );
    }

    public moveBy(selector: MoveBySelector, by: Partial<Vector3D>): RailingMutator {
        const { guardRailIndex = -1 } = selector.address;
        return this.mutateGuardRails((mutator) =>
            mutator.mutateItem(guardRailIndex, (itemMutator) => itemMutator.moveBy(selector, by)),
        );
    }

    public moveTo(selector: MoveToSelector): RailingMutator {
        const { guardRailIndex = -1 } = selector.address;
        return this.mutateGuardRails((mutator) =>
            mutator.mutateItem(guardRailIndex, (itemMutator) => itemMutator.moveTo(selector)),
        );
    }

    public rotateBy(selector: RailingsSelector, by: number, center: Point3D, rotationAxis: Vector3D): RailingMutator {
        switch (selector.type) {
            case RailingsSelectorType.GUARD_RAIL: {
                const {
                    address: { guardRailIndex },
                } = selector;
                return this.mutateGuardRails((guardRailsMutator) =>
                    guardRailsMutator.mutateItem(guardRailIndex, (guardRailMutator) =>
                        guardRailMutator.mutateStandard((domeMutator) =>
                            domeMutator.rotateBy(by, center, rotationAxis),
                        ),
                    ),
                );
            }
            case RailingsSelectorType.CORNER: {
                const {
                    address: { guardRailIndex },
                } = selector;
                return this.mutateGuardRails((guardRailsMutator) =>
                    guardRailsMutator.mutateItem(guardRailIndex, (guardRailMutator) =>
                        guardRailMutator.mutateCustom((customMutator) =>
                            customMutator.rotateBy(selector, by, center, rotationAxis).build(),
                        ),
                    ),
                );
            }
            default:
                return this;
        }
    }

    public removeInvalidGuardRails(): RailingMutator {
        const nextGuardRails = this.railing.guardRails.filter((guardRail) => !isDegenerated(guardRail));
        if (nextGuardRails.length === this.railing.guardRails.length) return this;
        return new RailingMutator(
            {
                ...this.railing,
                guardRails: nextGuardRails,
            },
            this.guardRailCreatorFactory,
        );
    }

    public addCorners(corners: GuardRailCorner[], roofs?: readonly Roof[]): RailingMutator {
        return this.guardRailCreatorFactory(this).addCorners(corners).done(roofs);
    }

    public generate(_ruleset: PlanRuleset, forPlanWithId: PlanId, roofs?: Roofs): RailingMutator {
        if (roofs === undefined) return this;
        const roofsValues = Object.values(roofs).filter(({ planId }) => planId === forPlanWithId);
        if (roofsValues.length === 0) return this;

        const automationRoof = getAutomationRoof(forPlanWithId);
        const pointCollection: Point3D[][] = [];

        for (const surfaceArea of automationRoof.getSurfaceAreasCompound().getAll()) {
            const surfaceOffset = automationRoof.createSurfaceOffset(surfaceArea, RoofOffsetMode.GuardrailGuidelines);

            for (const polyline of surfaceOffset.getPolylines()) {
                const points = polyline.map((p) => ({ x: p.x, y: p.y, z: 0 }));
                pointCollection.push(points);
            }
        }

        return pointCollection
            .filter((points) => points.length > 1)
            .reduce(
                (mutator, points) =>
                    mutator.addCorners(
                        points.map((p) => ({ position: p, id: createGuardRailCornerId() })),
                        roofsValues,
                    ),
                this as RailingMutator,
            )
            .nameGuardRails()
            .addSpecificationPlate(roofsValues);
    }

    public nameGuardRails(): RailingMutator {
        return this.useGuardRailsMetadata((guardRailsMeta, mutator) => {
            const customMetaWithIndex = guardRailsMeta
                .map((meta, index) => [meta, index] as [GuardRailMetadata, number])
                .filter(isCustomGuardRailMetadataWithIndex);
            customMetaWithIndex.sort(([{ length: l1 }], [{ length: l2 }]) => l2 - l1);
            return customMetaWithIndex.reduce(nameCustomGuardRails, mutator).mutateGuardRails((guardRailsMutator) =>
                guardRailsMutator.eachMatchingItem(
                    (guardRail) => isStandardGuardRail(guardRail),
                    (guardRailMutator, _, count) =>
                        guardRailMutator.mutateStandard((standardMutator) => standardMutator.setName(count)),
                ),
            );
        });
    }

    public useGuardRailsMetadata(
        fn: (metadata: GuardRailMetadata[], mutator: RailingMutator) => RailingMutator,
    ): RailingMutator {
        const { guardRails } = this.railing;
        const metadatas = guardRails.map(createGuardRailMetadata);
        return fn(metadatas, this);
    }

    public addSpecificationPlate(roofs?: readonly Roof[]): RailingMutator {
        return this.mutateGuardRails((guardRailsMutator) => {
            const { guardRails } = this.railing;

            const surfacesWithSpecificationPlates = new Set<string>();

            guardRails.forEach((guardRail) => {
                if (!isCustomGuardRail(guardRail)) return;

                const hasSpecificationPlate = guardRail.additions_v2?.generatedAdditions?.some(
                    (addition) => addition.id === GuardRailAdditionSlot.SPECIFICATION_PLATE,
                );

                if (hasSpecificationPlate === true) {
                    guardRail.edges.forEach((edge) => {
                        edge.posts?.forEach((post) => {
                            const projectedSurface = projectPointOnRoofs(post.position, roofs).surface;
                            if (projectedSurface !== undefined) {
                                surfacesWithSpecificationPlates.add(projectedSurface.id);
                            }
                        });
                    });
                }
            });

            const surfaceToGuardRailMap = new Map<string, CustomGuardRail>();

            guardRails.forEach((guardRail) => {
                if (!isCustomGuardRail(guardRail)) return;

                const surfaceIds = guardRail.edges.flatMap(
                    (edge) =>
                        edge.posts?.flatMap((post) => {
                            const projectedSurface = projectPointOnRoofs(post.position, roofs).surface;
                            return projectedSurface !== undefined ? [projectedSurface.id] : [];
                        }) ?? [],
                );

                surfaceIds.forEach((surfaceId) => {
                    if (!surfacesWithSpecificationPlates.has(surfaceId)) {
                        if (!surfaceToGuardRailMap.has(surfaceId)) {
                            surfaceToGuardRailMap.set(surfaceId, guardRail);
                        }
                    }
                });
            });

            return guardRailsMutator.eachMatchingItem(
                (guardRail) => [...surfaceToGuardRailMap.values()].some((gr) => gr.id === guardRail?.id),
                (guardRailMutator) =>
                    guardRailMutator.mutateCustom((customGuardRailMutator) => {
                        const surfaceCount = [...surfaceToGuardRailMap.entries()].filter(
                            ([_, gr]) => gr.id === guardRailMutator.done()?.id,
                        ).length;

                        return customGuardRailMutator.mutateProductAdditions((productAdditionMutator) =>
                            productAdditionMutator.addGeneratedAdditions([
                                {
                                    id: GuardRailAdditionSlot.SPECIFICATION_PLATE,
                                    product: createProductInstance("SG2-1009", {
                                        dimension: [surfaceCount],
                                        unit: ProductInstanceUnit.PCS,
                                    }),
                                },
                            ]),
                        );
                    }),
            );
        });
    }

    public createPosts(positions: Point3D[]): RailingMutator {
        return this.mutateGuardRails((mutator) =>
            mutator.eachItem((itemMutator) =>
                itemMutator.mutateCustom((customMutator) => customMutator.createPosts(positions).build()),
            ),
        );
    }

    public createGates(positions: Point3D[]): RailingMutator {
        return this.mutateGuardRails((mutator) =>
            mutator.eachItem((itemMutator) =>
                itemMutator.mutateCustom((customMutator) => customMutator.createGates(positions).build()),
            ),
        );
    }

    public joinGuardRails(leftIndex: number, rightIndex: number, joinWithEnd: boolean): RailingMutator {
        const leftGuardRail = this.railing.guardRails[leftIndex];
        const rightGuardRail = this.railing.guardRails[rightIndex];

        if (!isCustomGuardRail(leftGuardRail) || !isCustomGuardRail(rightGuardRail)) return this;

        const baseIndex = joinWithEnd ? leftIndex : rightIndex;
        const joinIndex = joinWithEnd ? rightIndex : leftIndex;
        const indexDiff = baseIndex - joinIndex;

        return indexDiff > 1
            ? this.mutateGuardRails((guardRailsMutator) => guardRailsMutator.deleteItem(leftIndex)).mutateGuardRails(
                  (guardRailsMutator) =>
                      guardRailsMutator.mutateItem(rightIndex, (itemMutator) =>
                          itemMutator.mutateCustom((customMutator) =>
                              customMutator.appendCorners([...leftGuardRail.corners].reverse()),
                          ),
                      ),
              )
            : this.mutateGuardRails((guardRailsMutator) => guardRailsMutator.deleteItem(joinIndex)).mutateGuardRails(
                  (guardRailsMutator) =>
                      guardRailsMutator.mutateItem(indexDiff > 0 ? baseIndex - indexDiff : baseIndex, (itemMutator) =>
                          itemMutator.mutateCustom((customMutator) =>
                              customMutator.prependCorners(
                                  [...(joinWithEnd ? rightGuardRail : leftGuardRail).corners].reverse(),
                              ),
                          ),
                      ),
              );
    }

    public pasteTo(copiedData: RailingCopyData, by: Vector3D): RailingMutator {
        const movedGuardRails = copiedData.map((guardRail) =>
            new GuardRailMutator(guardRail)
                .mutateStandard((standardMutator) => standardMutator.moveBy(by))
                .mutateCustom((customMutator) =>
                    customMutator
                        .mutateCorners((cornersMutator) =>
                            cornersMutator.eachItem((cornerMutator) => cornerMutator.moveBy(by)),
                        )
                        .mutateEdges((edgesMutator) =>
                            edgesMutator.eachItem((edgeMutator) =>
                                edgeMutator
                                    .mutatePosts((postsMutator) =>
                                        postsMutator.eachItem((postMutator) => postMutator.moveBy(by)),
                                    )
                                    .mutateGates((gatesMutator) =>
                                        gatesMutator.eachItem((gatesMutator) => gatesMutator.moveBy(by)),
                                    ),
                            ),
                        ),
                )
                .done(),
        );

        return this.mutateGuardRails((guardRailsMutator) => guardRailsMutator.appendItems(movedGuardRails));
    }

    public done(): Railing {
        return this.railing;
    }
}

const isDegenerated = (guardRail: GuardRail): boolean => isCustomGuardRail(guardRail) && guardRail.corners.length < 2;

const eachEqual =
    <T>(other: T[]) =>
    (equal: boolean, current: T, currentIndex: number, _self: T[]) =>
        equal && current === other[currentIndex];

const nameCustomGuardRails = (
    currentMutator: RailingMutator,
    [_, index]: [GuardRailMetadata, number],
    nameIndex: number,
) =>
    currentMutator.mutateGuardRails((guardRailsMutator) =>
        guardRailsMutator.mutateItem(index, (guardRailMutator) =>
            guardRailMutator.mutateCustom((customMutator) => customMutator.setName(nameIndex)),
        ),
    );

const isCustomGuardRailMetadataWithIndex = (
    metaWithIndex: [GuardRailMetadata, number],
): metaWithIndex is [CustomGuardRailMetadata, number] => isCustomGuardRailMetadata(metaWithIndex[0]);
