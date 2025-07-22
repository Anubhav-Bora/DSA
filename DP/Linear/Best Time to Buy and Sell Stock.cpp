#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int res(vector<int> &prices)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i : prices)
        {
            mini = min(mini, i);
            maxi = max(maxi, i - mini);
        }
        return maxi;
    }
    int maxProfit(vector<int> &prices)
    {
        return res(prices);
    }
};