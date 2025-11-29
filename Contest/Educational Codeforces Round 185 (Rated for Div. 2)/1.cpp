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
        int maxCost = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int val = (i - 1) * n + j;
                int cost = val;
                // up
                if (i > 1)
                {
                    cost += (i - 2) * n + j;
                }
                // down
                if (i < n)
                {
                    cost += (i)*n + j;
                }
                // left
                if (j > 1)
                {
                    cost += (i - 1) * n + (j - 1);
                }
                // right
                if (j < n)
                {
                    cost += (i - 1) * n + (j + 1);
                }
                maxCost = max(maxCost, cost);
            }
        }
        cout << maxCost << endl;
    }
}