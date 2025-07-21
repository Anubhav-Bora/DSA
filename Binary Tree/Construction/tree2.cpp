#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> &preorder, vector<int> &postorder,
                    unordered_map<int, int> &postIndex,
                    int &preorderIndex, int left, int right)
    {
        if (preorderIndex >= preorder.size() || left > right)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preorderIndex++]);

        if (left == right)
            return root;

        int leftRootVal = preorder[preorderIndex];
        int indexInPost = postIndex[leftRootVal];

        root->left = build(preorder, postorder, postIndex, preorderIndex, left, indexInPost);
        root->right = build(preorder, postorder, postIndex, preorderIndex, indexInPost + 1, right - 1);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++)
        {
            postIndex[postorder[i]] = i;
        }

        int preorderIndex = 0;
        return build(preorder, postorder, postIndex, preorderIndex, 0, postorder.size() - 1);
    }
};
