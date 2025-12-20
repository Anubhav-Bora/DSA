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
        vector<pair<long long, long long>> reindeer(n);

        for (int i = 0; i < n; i++)
        {
            cin >> reindeer[i].first >> reindeer[i].second;
        }

        sort(reindeer.begin(), reindeer.end(), [](pair<long long, long long> &a, pair<long long, long long> &b)
             { return (a.second + a.first) > (b.second + b.first); });

        int left = 0, right = n, ans = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            long long total_strength = 0;
            long long total_weight = 0;

            for (int i = 0; i < n - mid; i++)
            {
                total_strength += reindeer[i].second;
            }

            for (int i = n - mid; i < n; i++)
            {
                total_weight += reindeer[i].first;
            }

            if (total_strength >= total_weight)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }
}