#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int T = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != s[(i + 1) % n])
                T++;
        if (T == n)
            cout << T << "\n";
        else
            cout << T + 1 << "\n";
    }
}