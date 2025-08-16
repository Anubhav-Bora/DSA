#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));
        for (auto &q : queries)
        {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        // rowise prefix
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                diff[i][j] += diff[i][j - 1];
            }
        }
        // colomnwise
        for (int j = 0; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                diff[i][j] += diff[i - 1][j];
            }
        }
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = diff[i][j];
            }
        }
        return mat;
    }
};