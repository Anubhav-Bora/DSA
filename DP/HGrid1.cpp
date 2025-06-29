#include <bits/stdc++.h>
using namespace std;

/*int rec(int i, int j, int n, int m, vector<string> &matrix)
{
    // out of bounds or obstacle
    if (i >= n || j >= m || matrix[i][j] == '#')
        return 0;

    // reached destination
    if (i == n - 1 && j == m - 1)
        return 1;

    // explore right and down
    int right = rec(i + 1, j, n, m, matrix);
    int down = rec(i, j + 1, n, m, matrix);

    return right + down;
}*/

int rec(int i, int j, int n, int m, vector<string> &matrix, vector<vector<int>> &dp)
{
    // base case
    if (i == n - 1 && j == m - 1)
        return 1;

    if (i >= n || j >= m || matrix[i][j] == '#')
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = rec(i + 1, j, n, m, matrix, dp);
    int down = rec(i, j + 1, n, m, matrix, dp);

    return dp[i][j] = right + down;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i];

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = rec(0, 0, n, m, matrix, dp);

    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
