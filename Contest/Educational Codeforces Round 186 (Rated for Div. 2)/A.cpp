#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool has2026 = false, has2025 = false;

        for (int i = 0; i + 3 < n; i++)
        {
            if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '6')
                has2026 = true;

            if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5')
                has2025 = true;
        }
        string target = "2026";
        int ans = INT_MAX;
        if (has2026 || !has2025)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i + 3 < n; i++)
            {
                int cost = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (s[i + j] != target[j])
                    {
                        cost++;
                    }
                }
                ans = min(cost, ans);
            }
            cout << ans << endl;
        }
    }
}