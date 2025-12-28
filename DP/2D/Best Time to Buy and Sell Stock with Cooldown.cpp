#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int answer(int i, vector<int> &prices, bool Canbuy, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
        {
            return 0;
        }
        if (dp[i][Canbuy] != -1)
        {
            return dp[i][Canbuy];
        }
        int res = 0;
        if (Canbuy)
        {
            int buy = -prices[i] + answer(i + 1, prices, !Canbuy, dp);
            int not_buy = answer(i + 1, prices, Canbuy, dp);
            res = max(buy, not_buy);
        }
        else
        {
            int sell = +prices[i] + answer(i + 2, prices, !Canbuy, dp);
            int not_sell = answer(i + 1, prices, Canbuy, dp);
            res = max(sell, not_sell);
        }
        return dp[i][Canbuy] = res;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return answer(0, prices, true, dp);
    }
};