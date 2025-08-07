#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combi(vector<int> &current, int sum, int start,
               vector<vector<int>> &res, vector<int> &candidates, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            current.push_back(candidates[i]);
            combi(current, sum + candidates[i], i + 1, res, candidates, target);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> current;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combi(current, 0, 0, res, candidates, target);
        return res;
    }
};