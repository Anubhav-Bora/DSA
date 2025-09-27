#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l, r, c, x;
    int offset = 0;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> c;
            offset = (offset + c) % n;
            if (offset < 0)
                offset += n;
        }
        else
        {
            cin >> l >> r;
            int left = (l - 1 + offset) % n;
            int right = (r - 1 + offset) % n;
            long long sum = 0;
            if (left <= right)
            {
                sum = prefix[right + 1] - prefix[left];
            }
            else
            {
                sum = (prefix[n] - prefix[left]) + (prefix[right + 1] - prefix[0]);
            }
            cout << sum << endl;
        }
    }
}
