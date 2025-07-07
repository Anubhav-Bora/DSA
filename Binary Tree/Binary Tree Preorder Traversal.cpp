#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void dfs(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val); // Visit root
        dfs(root->left, res);     // Traverse left
        dfs(root->right, res);    // Traverse right
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
