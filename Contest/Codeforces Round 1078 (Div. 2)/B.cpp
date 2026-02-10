#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += (a[i] / x) * y;
        }

        
        long long maxVal = 0;

        for (int i = 0; i < n; i++)
        {
            long long result = a[i] + totalSum - (a[i] / x) * y;
            maxVal = max(maxVal, result);
        }

        cout << maxVal << endl;
    }

    return 0;
}