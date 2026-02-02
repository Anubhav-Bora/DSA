#include <bits/stdc++.h>
using namespace std;

void s()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = 0;
    int f = -1;
    int l = -1;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            c++;
            if (f == -1)
                f = i;
            l = i;
        }
    }

    if (c == 0)
    {
        cout << (n + 2) / 3 << "\n";
        return;
    }

    int a = 0;
    a += (f + 1) / 3;

    int x = n - 1 - l;
    a += (x + 1) / 3;

    int p = f;
    for (int i = f + 1; i < n; ++i)
    {
        if (s[i] == '1')
        {
            int g = i - p - 1;
            a += g / 3;
            p = i;
        }
    }

    cout << c + a << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s();
    }
    return 0;
}
