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

        vector<int> p(n + 1, 0);
        vector<bool> used(n + 1, false);

        p[n] = n;
        used[n] = true;

        for (int i = n - 1; i >= 1; i--)
        {
            int candidate = p[i + 1] - i;
            if (candidate >= 1 && candidate <= n && !used[candidate])
            {
                p[i] = candidate;
            }
            else
            {
                p[i] = p[i + 1] + i;
            }
            used[p[i]] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
