#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, int rem, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n)
            return 0;
        int newRem = (rem + grid[i][j]) % k;
        if (i == m - 1 && j == n - 1)
        {
            if (newRem == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][j][newRem] != -1)
            return dp[i][j][newRem];
        int down = solve(i + 1, j, newRem, grid, k, dp);
        int right = solve(i, j + 1, newRem, grid, k, dp);
        return dp[i][j][newRem] = (down + right) % 1000000007;
    }
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k, dp);
    }
};