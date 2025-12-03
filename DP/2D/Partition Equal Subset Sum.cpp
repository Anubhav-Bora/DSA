#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (i == nums.size() || target < 0)
            return false;
        if (dp[i][target] != -1)
            return dp[i][target];
        bool include = solve(i + 1, nums, target - nums[i], dp);
        bool exclude = solve(i + 1, nums, target, dp);
        return dp[i][target] = include || exclude;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        return solve(0, nums, target, dp);
    }
};