#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 2)
    {
        cout << -1 << " " << 2 << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 && n % 2 == 0)
        {
            cout << 2;
        }
        else if (i % 2 == 0)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << 3 << " ";
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
}
