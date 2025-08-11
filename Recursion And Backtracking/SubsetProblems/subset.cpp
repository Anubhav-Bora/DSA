#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sol(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i)
    {
        if (i >= nums.size())
        {
            res.push_back(curr);
            return;
        }
        // include
        curr.push_back(nums[i]);
        sol(nums, res, curr, i + 1);
        curr.pop_back(); // backtrack
        // exclude
        sol(nums, res, curr, i + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        sol(nums, res, curr, 0);
        return res;
    }
};