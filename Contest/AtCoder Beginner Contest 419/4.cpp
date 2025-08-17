#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string s, t;
    cin >> s >> t;

    vector<int> cum(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >> l >> r;
        cum[l - 1] += 1;
        cum[r] -= 1;
    }

    for (int i = 0; i < N; i++)
    {
        cum[i + 1] += cum[i];
    }

    string ans = "";
    for (int i = 0; i < N; i++)
    {
        if (cum[i] % 2 == 0)
            ans += s[i];
        else
            ans += t[i];
    }

    cout << ans << "\n";
    return 0;
}
