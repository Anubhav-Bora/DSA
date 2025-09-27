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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int zeros = 0, negatives = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                zeros++;
            else if (a[i] < 0)
                negatives++;
        }

        int ans = zeros;
        if (negatives % 2 == 1)
            ans += 2;

        cout << ans << endl;
    }
    return 0;
}