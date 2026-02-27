#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool nonDecreasing = true;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                nonDecreasing = false;
                break;
            }
        }

        cout << (nonDecreasing ? n : 1) << endl;
    }

    return 0;
}
