#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int ans = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                int maxi = INT_MIN;
                if (i + 1 < m)
                {
                    maxi = max(maxi, dp[i + 1][j]);
                }
                if (j + 1 < n)
                {
                    maxi = max(maxi, dp[i][j + 1]);
                }
                ans = max(ans, maxi - grid[i][j]);
                dp[i][j] = max(maxi, grid[i][j]);
            }
        }
        return ans;
    }
};