#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combi(int n, int row, vector<bool> &col, vector<bool> &diag,
               vector<bool> &anti, vector<string> &current,
               vector<vector<string>> &res)
    {
        if (row == n)
        {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (col[i] || diag[row - i + n - 1] || anti[row + i])
                continue;
            col[i] = diag[row - i + n - 1] = anti[row + i] = true;
            string s(n, '.');
            s[i] = 'Q';
            current.push_back(s);
            combi(n, row + 1, col, diag, anti, current, res);
            current.pop_back();
            col[i] = diag[row - i + n - 1] = anti[row + i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> col(n, false);
        vector<bool> diag(2 * n - 1, false);
        vector<bool> anti(2 * n - 1, false);
        vector<vector<string>> res;
        vector<string> current;

        combi(n, 0, col, diag, anti, current, res);
        return res;
    }
};
