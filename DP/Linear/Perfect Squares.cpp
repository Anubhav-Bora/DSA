#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int res(int n, int sum, vector<int> &sq, vector<int> &dp)
    {
        if (sum == n)
        {
            return 0;
        }
        if (sum > n)
            return INT_MAX;
        int minCount = INT_MAX;
        if (dp[sum] != -1)
        {
            return dp[sum];
        }
        for (int i = 0; i < sq.size(); i++)
        {
            // take
            int next = res(n, sum + sq[i], sq, dp);
            if (next != INT_MAX)
            {
                minCount = min(minCount, 1 + res(n, sum + sq[i], sq, dp));
            }
        }
        dp[sum] = minCount;
        return minCount;
    }
    int numSquares(int n)
    {
        vector<int> sq;
        for (int i = 1; i * i <= n; i++)
        {
            sq.push_back(i * i);
        }
        vector<int> dp(n + 1, -1);
        return res(n, 0, sq, dp);
    }
};