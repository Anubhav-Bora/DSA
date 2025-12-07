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
        set<int> colors;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            colors.insert(a[i]);
        }

        int current_distinct = colors.size();

        while (colors.find(current_distinct) == colors.end())
        {
            colors.insert(current_distinct);
            current_distinct = colors.size();
        }

        cout << current_distinct << endl;
    }

    return 0;
}