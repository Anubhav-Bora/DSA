#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &nums, int i, int preIndex, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
            return 0;

        if (dp[i][preIndex + 1] != -1)
            return dp[i][preIndex + 1];

        int exclude = sol(nums, i + 1, preIndex, dp);

        int include = 0;
        if (preIndex == -1 || nums[i] > nums[preIndex])
        {
            include = 1 + sol(nums, i + 1, i, dp);
        }

        return dp[i][preIndex + 1] = max(include, exclude);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return sol(nums, 0, -1, dp);
    }
};
