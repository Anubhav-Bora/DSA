#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    prefix[0][0] = grid[0][0];
                }
                else if (i == 0)
                {
                    prefix[0][j] = prefix[0][j - 1] + grid[0][j];
                }
                else if (j == 0)
                {
                    prefix[i][0] = prefix[i - 1][0] + grid[i][0];
                }
                else
                {
                    prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i][j];
                }
                if (prefix[i][j] <= k)
                    count++;
            }
        }
        return count;
    }
};