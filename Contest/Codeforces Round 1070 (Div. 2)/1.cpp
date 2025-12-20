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

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n;)
            {
                if (a[j] < a[i])
                {
                    a.erase(a.begin() + j);
                    n--;
                    count++;
                }
                else
                {
                    j++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}