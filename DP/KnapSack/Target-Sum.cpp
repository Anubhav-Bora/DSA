#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int solve(int i, vector<int> &nums, int target, int sum)
    {
        if (i == nums.size())
        {
            return sum == target;
        }

        if (dp[i].count(sum))
            return dp[i][sum];

        return dp[i][sum] =
                   solve(i + 1, nums, target, sum + nums[i]) +
                   solve(i + 1, nums, target, sum - nums[i]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solve(0, nums, target, 0);
    }
};
