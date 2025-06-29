#include <bits/stdc++.h>
using namespace std;
/*long res(int i, long n, long W, vector<long> &v, vector<long> &w)
{
    if (i >= n)
    {
        return 0;
    }
    // notTake
    long not_take = res(i + 1, n, W, v, w);
    // Take
    long take = LONG_MIN;
    if (w[i] <= W)
    {
        take = v[i] + res(i + 1, n, W - w[i], v, w);
    }
    return max(take, not_take);
}

int solve()
{
    long n;
    long W;
    cin >> n >> W;
    vector<long> v(n);
    vector<long> w(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    long ans = res(0, n, W, v, w);
    cout << ans;
}*/
/*long res(int i, long n, long W, vector<long> &v, vector<long> &w, vector<vector<long>> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    // notTake
    long not_take = res(i + 1, n, W, v, w, dp);
    // Take
    long take = LONG_MIN;
    if (w[i] <= W)
    {
        take = v[i] + res(i + 1, n, W - w[i], v, w, dp);
    }
    return dp[i][W] = max(take, not_take);
}

int solve()
{
    long n;
    long W;
    cin >> n >> W;
    vector<long> v(n);
    vector<long> w(n);
    vector<vector<long>> dp(n + 1, vector<long>(W + 1, -1));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    long ans = res(0, n, W, v, w, dp);
    cout << ans;
}*/
long res(long n, long W, vector<long> &v, vector<long> &w)
{
    vector<vector<long>> dp(n + 1, vector<long>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            // Not take item
            dp[i][cap] = dp[i - 1][cap];

            // Take item
            if (w[i - 1] <= cap)
            {
                dp[i][cap] = max(dp[i][cap], v[i - 1] + dp[i - 1][cap - w[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int solve()
{
    long n, W;
    cin >> n >> W;
    vector<long> v(n), w(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    long ans = res(n, W, v, w);
    cout << ans;
    return 0;
}

int main()
{
    solve();
    return 0;
}
