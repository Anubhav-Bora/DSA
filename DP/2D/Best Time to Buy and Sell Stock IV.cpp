#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, vector<int> &prices, int k, bool buy, int count, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (count == k)
        {
            return 0;
        }
        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];
        if (buy)
        {
            int buys = -prices[i] + solve(i + 1, prices, k, !buy, count, dp); // buy
            int notBuy = solve(i + 1, prices, k, buy, count, dp);             // notBuy
            return dp[i][buy][count] = max(buys, notBuy);
        }
        else
        {
            int sell = prices[i] + solve(i + 1, prices, k, !buy, count + 1, dp); // sell
            int notSell = solve(i + 1, prices, k, buy, count, dp);
            return dp[i][buy][count] = max(sell, notSell);
        }
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // 3d dp since 3 states chaning i,boolean(0/1),count
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, prices, k, true, 0, dp);
    }
};