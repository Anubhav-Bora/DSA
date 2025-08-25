
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
    int dfs(TreeNode *root, int &globalMax)
    {
        if (!root)
            return 0;
        int left = max(0, dfs(root->left, globalMax));
        int right = max(0, dfs(root->right, globalMax));
        globalMax = max(globalMax, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        int globalMax = INT_MIN;
        dfs(root, globalMax);
        return globalMax;
    }
};