#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int aheadBuy = 0;
        int aheadSell = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int currBuy = max(-prices[i] + aheadSell, aheadBuy);
            int currSell = max(prices[i] - fee + aheadBuy, aheadSell);

            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};