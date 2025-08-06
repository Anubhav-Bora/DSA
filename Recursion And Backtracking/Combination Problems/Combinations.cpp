#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void combi(int n, int k, int start, vector<int> &current, vector<vector<int>> &res)
    {
        if (current.size() == k)
        {
            res.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            current.push_back(i);
            combi(n, k, i + 1, current, res);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> current;
        vector<vector<int>> res;
        combi(n, k, 1, current, res);
        return res;
    }
};