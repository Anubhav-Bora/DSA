#include <bits/stdc++.h>
using namespace std;

int findCost(string &t, vector<string> &p, vector<int> &cost, bool change)
{
    int n = t.size(), m = p.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int pos = 0; pos < n; pos++)
    {
        if (dp[pos] == INT_MAX)
            continue;

        for (int i = 0; i < m; i++)
        {
            int next = pos;
            if (change)
            {
                int cnt[26] = {0};
                for (char ch : p[i])
                    cnt[ch - 'a']++;
                while (next < n && cnt[t[next] - 'a'] > 0)
                {
                    cnt[t[next] - 'a']--;
                    next++;
                }
            }
            else
            {
                for (char ch : p[i])
                {
                    if (next < n && ch == t[next])
                        next++;
                }
            }
            if (next > pos)
            {
                dp[next] = min(dp[next], dp[pos] + cost[i]);
            }
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> p(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int a = findCost(s, p, c, false);
    int b = findCost(s, p, c, true);
    cout << a - b;
    return 0;
}