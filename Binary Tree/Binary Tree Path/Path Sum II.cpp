
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
    void findAll(TreeNode *root, int target, vector<int> &path,
                 vector<vector<int>> &allPath)
    {
        if (!root)
            return;
        path.push_back(root->val);
        int sum = 0;
        for (int x : path)
        {
            sum += x;
        }
        if (!root->left && !root->right && sum == target)
        {
            allPath.push_back(path);
        }
        else
        {
            findAll(root->left, target, path, allPath);
            findAll(root->right, target, path, allPath);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> allPath;
        findAll(root, targetSum, path, allPath);
        return allPath;
    }
};