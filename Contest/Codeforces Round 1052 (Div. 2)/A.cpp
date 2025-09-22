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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        vector<int> f;
        for (auto &p : freq)
            f.push_back(p.second);
        int maxf = *max_element(f.begin(), f.end());
        int ans = 0;
        for (int c = 1; c <= maxf; c++)
        {
            int cnt = 0;
            for (int v : f)
                if (v >= c)
                    cnt++;
            ans = max(ans, cnt * c);
        }
        cout << ans << endl;
    }
}