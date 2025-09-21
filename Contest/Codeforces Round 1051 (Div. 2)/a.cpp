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
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool check = true;
        int curr = 1;
        int l = 0;
        int r = n - 1;
        while (curr <= n)
        {
            if (arr[l] == curr)
            {
                curr++;
                l++;
                continue;
            }
            if (arr[r] == curr)
            {
                curr++;
                r--;
                continue;
            }
            check = false;
            break;
        }
        if (check)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}