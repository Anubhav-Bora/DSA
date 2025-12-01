#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || i == coins.size())
            return 0;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int count = 0;
        // take
        count += solve(i, amount - coins[i], coins, dp);
        // not take
        count += solve(i + 1, amount, coins, dp);
        return dp[i][amount] = count;
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }
};