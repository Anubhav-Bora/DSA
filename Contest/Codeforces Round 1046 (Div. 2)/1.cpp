#include <bits/stdc++.h>
using namespace std;

bool valid(int x, int y)
{
    return y <= 2 * x + 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = min(a, b), y = max(a, b);
        int x1 = min(c - a, d - b);
        int y1 = max(c - a, d - b);
        if (valid(x, y) && valid(x1, y1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
