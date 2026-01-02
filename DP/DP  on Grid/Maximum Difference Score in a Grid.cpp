class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return INT_MIN;

        if (dp[i][j] != -1)
            return dp[i][j];

        int best = INT_MIN;

        if (i + 1 < m)
            best = max(best, grid[i + 1][j]);

        if (j + 1 < n)
            best = max(best, grid[i][j + 1]);

        int down = (i + 1 < m) ? solve(i + 1, j, grid, dp) : INT_MIN;
        int right = (j + 1 < n) ? solve(i, j + 1, grid, dp) : INT_MIN;

        best = max(best, max(down, right));

        dp[i][j] = best;
        return best;
    }

    int maxScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int futureMax = solve(i, j, grid, dp);
                if (futureMax != INT_MIN)
                    ans = max(ans, futureMax - grid[i][j]);
            }
        }
        return ans;
    }
};
