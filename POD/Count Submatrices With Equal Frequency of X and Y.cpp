#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> countX(m, 0);
        vector<int> countY(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            int y = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'X')
                    x++;
                else if (grid[i][j] == 'Y')
                    y++;
                countX[j] += x;
                countY[j] += y;

                if (countX[j] > 0 && countX[j] == countY[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};