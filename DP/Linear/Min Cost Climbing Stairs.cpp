#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStep(int i, vector<int> &cost, vector<int> &dp)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = cost[i] + min(minStep(i + 1, cost, dp), minStep(i + 2, cost, dp));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size(), -1);
        return min(minStep(0, cost, dp), minStep(1, cost, dp));
    }
};