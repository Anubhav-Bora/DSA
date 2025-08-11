#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sol(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int i)
    {
        if (i >= nums.size())
        {
            if (find(res.begin(), res.end(), curr) == res.end())
            {
                res.push_back(curr);
            }
            return;
        }
        // include
        curr.push_back(nums[i]);
        sol(nums, curr, res, i + 1);
        curr.pop_back();
        sol(nums, curr, res, i + 1); // exclude
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> res;
        sol(nums, curr, res, 0);
        return res;
    }
};