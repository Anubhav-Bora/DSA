#include <bits/stdc++.h>
using namespace std;

int res(int a[], int b[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            count += a[i] - b[i];
    return count + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int b[n];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cout << res(a, b, n) << "\n";
    }
    return 0;
}
