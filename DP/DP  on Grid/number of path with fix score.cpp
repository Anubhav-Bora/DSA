#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;

    vector<int> sol(int r, int c, vector<string> &board,
                    vector<vector<vector<int>>> &dp)
    {

        // obstacle
        if (board[r][c] == 'X')
            return {0, 0};

        // start cell
        if (r == 0 && c == 0)
            return {0, 1};

        // if already computed
        if (dp[r][c][0] != -1)
            return dp[r][c];

        vector<int> left = {0, 0}, up = {0, 0}, diag = {0, 0};

        if (c - 1 >= 0)
            left = sol(r, c - 1, board, dp);

        if (r - 1 >= 0)
            up = sol(r - 1, c, board, dp);

        if (r - 1 >= 0 && c - 1 >= 0)
            diag = sol(r - 1, c - 1, board, dp);

        int maxSum = max(left[0], max(up[0], diag[0]));
        int ways = 0;

        if (left[0] == maxSum)
            ways = (ways + left[1]) % mod;
        if (up[0] == maxSum)
            ways = (ways + up[1]) % mod;
        if (diag[0] == maxSum)
            ways = (ways + diag[1]) % mod;

        if (ways == 0)
            return dp[r][c] = {0, 0};

        if (board[r][c] != 'S')
            maxSum = (maxSum + board[r][c] - '0') % mod;

        return dp[r][c] = {maxSum, ways};
    }

    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int n = board.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1)));

        return sol(n - 1, n - 1, board, dp);
    }
};