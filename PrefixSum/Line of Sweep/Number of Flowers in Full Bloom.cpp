#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        map<int, int> diff;
        for (auto &it : flowers)
        {
            int l = it[0];
            int r = it[1];
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        map<int, int> bloomCount;
        int active = 0;
        for (auto &[i, j] : diff)
        {
            active += j;
            bloomCount[i] = active;
        }
        vector<int> ans;
        for (int t : people)
        {
            auto it = bloomCount.upper_bound(t);
            if (it == bloomCount.begin())
                ans.push_back(0);
            else
            {
                it--;
                ans.push_back((it)->second);
            }
        }
        return ans;
    }
};
