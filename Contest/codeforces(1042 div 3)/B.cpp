#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                cout << -1 << " ";
            else
                cout << 3 << " ";
        }
    }
    else
    {
        if (n == 2)
        {
            cout << -1 << " " << 2;
        }
        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                if (i % 2 == 0)
                    cout << -1 << " ";
                else
                    cout << 3 << " ";
            }
            cout << -1 << " " << 2;
        }
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
