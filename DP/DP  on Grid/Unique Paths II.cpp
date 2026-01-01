#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int paths(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = paths(i, j + 1, grid, m, n, dp);
        int down = paths(i + 1, j, grid, m, n, dp);
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return paths(0, 0, obstacleGrid, m, n, dp);
    }
};