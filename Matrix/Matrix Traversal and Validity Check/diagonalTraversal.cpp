#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        if (m == 0)
            return {};
        int n = mat[0].size();

        vector<int> res;
        int total = m * n;

        int r = 0, c = 0;
        bool up = true;

        for (int k = 0; k < total; ++k)
        {
            res.push_back(mat[r][c]);
            int nr = r + (up ? -1 : 1);
            int nc = c + (up ? 1 : -1);

            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
                r = nr;
                c = nc;
            }
            else
            {
                if (up)
                {
                    if (c + 1 < n)
                        c++;
                    else
                        r++;
                }
                else
                {
                    if (r + 1 < m)
                        r++;
                    else
                        c++;
                }
                up = !up;
            }
        }
        return res;
    }
};
