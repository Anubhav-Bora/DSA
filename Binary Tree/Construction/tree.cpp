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
    TreeNode *BuildTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &inorderMap, int &postIndex, int left, int right)
    {
        if (left > right)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);

        int index = inorderMap[rootVal];

        root->right = BuildTree(inorder, postorder, inorderMap, postIndex, index + 1, right);
        root->left = BuildTree(inorder, postorder, inorderMap, postIndex, left, index - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return BuildTree(inorder, postorder, inorderMap, postIndex, 0, inorder.size() - 1);
    }
};
