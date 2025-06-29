#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rec(int i, int sum, int total, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
        {
            return sum == total / 2;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int not_take = rec(i + 1, sum, total, nums, dp);
        int take = false;
        if (sum + nums[i] <= total / 2)
        {
            take = rec(i + 1, sum + nums[i], total, nums, dp);
        }
        return dp[i][sum] = take || not_take;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int total = 0;
        for (auto &it : nums)
        {
            total += it;
        }
        if (total % 2 != 0)
            return false;
        vector<vector<int>> dp(n + 1, vector<int>(total / 2 + 1, -1));
        return rec(0, 0, total, nums, dp);
    }
};
