import{useLanguage} from "@abs/translations";
import{asyncLoadScript} from "@abs/utils";
import LocationOnIcon from "@mui/icons-material/LocationOn";
import{Autocomplete} from "@mui/material";
import Grid from "@mui/material/Grid";
import{Theme} from "@mui/material/styles";
import TextField from "@mui/material/TextField";
import Typography from "@mui/material/Typography";
import{makeStyles} from "@mui/styles";
import React from "react";
import{useTranslation} from "react-i18next";
import{GoogleLocation} from "../../type/ProjectForm";
import{getGoogleLocation, getLocationDescription} from "./helper";

const useStyles = makeStyles<Theme>((theme) = > ({
                                                  icon : {
                                                      color : theme.palette.text.secondary,
                                                      marginRight : theme.spacing(2),
                                                  },
                                              }));

function useDebouncedValue<T>(value : T, delay : number) : T
{
    const[debouncedValue, setDebouncedValue] = React.useState(value);

    React.useEffect(() = > {
        const handler = setTimeout(() = > {
            setDebouncedValue(value);
        },
                                   delay);

        return () =>
        {
            clearTimeout(handler);
        };
    },
                    [ value, delay ]);

    return debouncedValue;
}

type LocationAutocompleteProps = {
    id : string;
testId : string;
label : string;
value : string;
error ?: string;
onChange : (value : string) = > void;
onSelectLocation ?: (location ?: GoogleLocation) = > void;
}
;

export type GooglePlaceOption = {
    mainText : string;
secondaryText : string;
placeId : string;
formattedAddress : string;
}
;

const LocationAutocomplete = ({
    id,
    testId,
    label,
    value,
    error,
    onChange,
    onSelectLocation,
} : LocationAutocompleteProps) =>
{
    const classes = useStyles();
    const {t} = useTranslation();
    const {locale} = useLanguage();
    const[options, setOptions] = React.useState<GooglePlaceOption[]>([]);
    const[hasScriptLoaded, setScriptLoaded] = React.useState<boolean>(false);
    const[inputValue, setInputValue] = React.useState<string>(value);
    const[selectedValue, setSelectedValue] = React.useState<GooglePlaceOption | string | null>(null);

    const debouncedInput = useDebouncedValue(inputValue, 400);

    React.useEffect(() = > {
        setInputValue(value);
    },
                    [value]);

    React.useEffect(() = > {
        asyncLoadScript(
            "google-maps-script",
            https : // maps.googleapis.com/maps/api/js?key=${process.env.GOOGLE_API_KEY}&libraries=places,marker,
            () = > setScriptLoaded(true), );
    },
                    []);

    React.useEffect(() = > {
        if (!hasScriptLoaded || debouncedInput.trim().length == = 0)
        {
            setOptions([]);
            return;
        }

        const request : google.maps.places.AutocompleteRequest = {
            input : debouncedInput,
            locationBias : {radius : 50000, center : new google.maps.LatLng({lat : 51.1657, lng : 10.4515})},
            language : locale,
        };

        google.maps.places.AutocompleteSuggestion.fetchAutocompleteSuggestions(request)
            .then(async({suggestions}) = > {
                const results = await Promise.all(
                    suggestions.map(async(sugg) = > {
                        const prediction = sugg     ?.placePrediction;
                        const mainText = prediction ?.mainText ?.text;
                        const secondaryText = prediction ?.secondaryText ?.text;
                        const placeId = prediction                       ?.placeId;

                        if (!mainText || !placeId)
                            return null;

                        try
                        {
                            const service = new google.maps.places.PlacesService(document.createElement("div"));
                            const place = await new Promise<google.maps.places.PlaceResult | null>(
                                (resolve, reject) = > {
                                    service.getDetails(
                                        {
                                            placeId,
                                            language : locale,
                                            fields : ["formatted_address"],
                                        },
                                        (result, status) = > {
                                            if (status == = google.maps.places.PlacesServiceStatus.OK)
                                            {
                                                resolve(result);
                                            }
                                            else
                                            {
                                                console.error("Failed to fetch place details:", status);
                                                resolve(null);
                                            }
                                        }, );
                                }, );

                            if (!place || !place.formatted_address)
                            {
                                return null;
                            }

                            return {
                                mainText,
                                secondaryText : secondaryText || "",
                                placeId,
                                formattedAddress : place.formatted_address,
                            };
                        }
                        catch (err)
                        {
                            console.error("Failed to fetch details:", err);
                            return null;
                        }
                    }), );

                const validResults = results.filter((result) : result is GooglePlaceOption = > result != = null);
                setOptions(validResults);
            })
            .catch((error) = > {
                console.error("Error fetching autocomplete suggestions:", error);
                setOptions([]);
            });
    },
                    [ hasScriptLoaded, debouncedInput, locale ]);

    const handleChange = (_event : any, newValue : GooglePlaceOption | string | null) =>
    {
        setSelectedValue(newValue);

        if (typeof newValue == = "string")
        {
            setInputValue(newValue);
            onChange(newValue);
            onSelectLocation ?.();
        }
        else if (newValue &&typeof newValue == = "object")
        {
            setInputValue(newValue.formattedAddress);
            onChange(newValue.formattedAddress);
            onSelectLocation ?.(getGoogleLocation(newValue));
        }
        else
        {
            setInputValue("");
            onChange("");
            onSelectLocation ?.();
        }
    };

    const handleInputChange = (_event : any, newInputValue : string) =>
    {
        setInputValue(newInputValue);
        onChange(newInputValue);

        const matchingOption = options.find((opt) = > opt.formattedAddress == = newInputValue);
        if (!matchingOption)
        {
            setSelectedValue(newInputValue);
        }
    };

    const handleBlur = () =>
    {
        const validOption = options.find((option) = > option.formattedAddress == = inputValue);
        if (validOption && onSelectLocation)
        {
            onSelectLocation(getGoogleLocation(validOption));
        }
        else if (onSelectLocation)
        {
            onSelectLocation(undefined);
        }
    };

    return (
        <Autocomplete
            filterOptions={(options) => options}
            freeSolo
            autoHighlight
            autoComplete
            selectOnFocus
            clearOnBlur
            handleHomeEndKeys
            id={id}
            value={selectedValue}
            inputValue={inputValue}
            options={options}
            noOptionsText={t("location_autocomplete.no_options_text")}
            getOptionLabel={
        (option) =>
        {
            if (typeof option == = "string")
                return option;
            return getLocationDescription(option);
        }}
            isOptionEqualToValue={
        (option, value) =>
        {
            if (typeof option == = "string" &&typeof value == = "string")
            {
                return option == = value;
            }
            if (typeof option == = "object" &&typeof value == = "object")
            {
                return option.placeId == = value.placeId;
            }
            return false;
        }}
            onChange={handleChange}
            onBlur={handleBlur}
            onInputChange={handleInputChange}
            renderInput={(params) => (
                <TextField
                    {...params}
                    fullWidth
                    data-testid={testId}
                    label={label}
                    error={!!error}
                    helperText={error}
                    margin="normal"
                    onKeyDown={(event) => {
                        if (event.key === "Enter" && value === "") event.preventDefault();
                    }
}
                />
            )
                }
            renderOption={(props, option) => (
                <li {...props}>
                    <Grid container alignItems="center">
                        <Grid item>
                            <LocationOnIcon className={classes.icon} />
                        </Grid>
                        <Grid item xs>
                            <span style={{ fontWeight: 700 }}>{option.mainText}</span>
                            <Typography variant="body2" color="textSecondary">
                                {option.formattedAddress}
                            </Typography>
                        </Grid>
                    </Grid>
                </li>
            )}
        />
    );
            }
            ;

            export default LocationAutocomplete;