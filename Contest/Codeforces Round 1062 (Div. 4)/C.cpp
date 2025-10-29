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
        vector<int> toys(n);
        for (int i = 0; i < n; i++)
        {
            cin >> toys[i];
        }
        bool hasEven = false, hasOdd = false;
        for (int i = 0; i < n; i++)
        {
            if (toys[i] % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }
        if (hasEven && hasOdd)
        {
            sort(toys.begin(), toys.end());
        }
        for (int i = 0; i < n; i++)
        {
            cout << toys[i] << " ";
        }
        cout << "\n";
    }
}