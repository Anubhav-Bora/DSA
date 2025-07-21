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
    int dia(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;

        int leftHeight = dia(root->left, diameter);
        int rightHeight = dia(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        dia(root, diameter);
        return diameter;
    }
};
