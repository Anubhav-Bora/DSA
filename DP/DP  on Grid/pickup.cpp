#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i1, int j1, int i2, vector<vector<int>> &grid, int n, vector<vector<vector<int>>> &dp)
    {
        int j2 = i1 + j1 - i2; // i1+j1=i2+j2
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n)
            return -1e9;
        if (grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e9;
        if (i1 == n - 1 && j1 == n - 1)
            return grid[i1][j1];

        if (dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];

        int count = 0;
        if (i1 == i2 && j1 == j2)
            count += grid[i1][j1];
        else
            count += grid[i1][j1] + grid[i2][j2];

        int best = max({
            solve(i1 + 1, j1, i2 + 1, grid, n, dp), // both down
            solve(i1, j1 + 1, i2, grid, n, dp),     // both right
            solve(i1 + 1, j1, i2, grid, n, dp),     // P1 down, P2 right
            solve(i1, j1 + 1, i2 + 1, grid, n, dp)  // P1 right, P2 down
        });

        return dp[i1][j1][i2] = count + best;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(0, 0, 0, grid, n, dp));
    }
};
