#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (dp[amount] != -2)
        {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (auto &coin : coins)
        {
            int count = solve(coins, amount - coin, dp);
            if (count != -1)
            {
                mini = min(mini, count + 1);
            }
        }

        dp[amount] = (mini == INT_MAX) ? -1 : mini;
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -2);
        return solve(coins, amount, dp);
    }
};
