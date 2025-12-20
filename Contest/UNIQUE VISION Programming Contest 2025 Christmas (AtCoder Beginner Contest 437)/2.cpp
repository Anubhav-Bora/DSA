#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col, n;
    cin >> row >> col >> n;

    vector<vector<int>> grid(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int res = 0;
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
        {
            if (s.count(grid[i][j]))
            {
                count++;
            }
        }
        res = max(res, count);
    }

    cout << res << endl;
    return 0;
}