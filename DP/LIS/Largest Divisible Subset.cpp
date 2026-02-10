
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums, int index, int prev,
              vector<vector<int>> &dp)
    {

        if (index == nums.size())
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int not_take = solve(nums, index + 1, prev, dp);

        int take = 0;
        if (prev == -1 || nums[index] % nums[prev] == 0)
        {
            take = 1 + solve(nums, index + 1, index, dp);
        }

        return dp[index][prev + 1] = max(take, not_take);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        solve(nums, 0, -1, dp);

        // Reconstruct subset
        vector<int> result;
        int index = 0, prev = -1;

        while (index < n)
        {
            int not_take = solve(nums, index + 1, prev, dp);

            if (prev == -1 || nums[index] % nums[prev] == 0)
            {
                int take = 1 + solve(nums, index + 1, index, dp);

                if (take >= not_take)
                {
                    result.push_back(nums[index]);
                    prev = index;
                }
            }

            index++;
        }

        return result;
    }
};
