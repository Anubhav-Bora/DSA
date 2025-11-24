#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int res(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            total += res(i - 1, dp) * res(n - i, dp);
        }
        return dp[n] = total;
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return res(n, dp);
    }
};