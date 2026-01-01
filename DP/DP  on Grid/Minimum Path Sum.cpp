#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSum(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = minSum(i + 1, j, grid, m, n, dp);
        int right = minSum(i, j + 1, grid, m, n, dp);

        int best = min(down, right);
        if (best == INT_MAX)
            return INT_MAX;

        return dp[i][j] = grid[i][j] + best;
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return minSum(0, 0, grid, grid.size(), grid[0].size(), dp);
    }
};
