
// See the leetcode version
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> colMap;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto curr = q.front().first;
            auto pos = q.front().second;
            q.pop();

            int row = pos.first;
            int col = pos.second;

            colMap[col].push_back({row, curr->val});

            if (curr->left)
            {
                q.push({curr->left, {row + 1, col - 1}});
            }
            if (curr->right)
            {
                q.push({curr->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> res;
        for (auto &entry : colMap)
        {
            auto &nodes = entry.second;
            sort(nodes.begin(), nodes.end());

            vector<int> colVals;
            for (auto &p : nodes)
            {
                colVals.push_back(p.second);
            }
            res.push_back(colVals);
        }
        return res;
    }
};
