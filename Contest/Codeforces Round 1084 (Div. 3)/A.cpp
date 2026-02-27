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
        vector<int> dish(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dish[i];
        }

        int mx = *max_element(dish.begin(), dish.end());
        int winners = 0;
        for (int x : dish)
        {
            if (x == mx)
                winners++;
        }

        cout << winners << endl;
    }

    return 0;
}
