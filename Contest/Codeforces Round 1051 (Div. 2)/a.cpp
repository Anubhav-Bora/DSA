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
        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        bool validRange = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i] < 1 || p[i] > n)
            {
                validRange = false;
                break;
            }
        }

        if (!validRange)
        {
            cout << "NO" << endl;
            continue;
        }

        int maxPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] == n)
            {
                maxPos = i;
                break;
            }
        }

        bool ans = false;
        ans = (maxPos == n / 2);

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}