#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> vals;
    vector<long long> gain;

    long long solve(int i, vector<long long> &dp)
    {
        if (i >= vals.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long skip = solve(i + 1, dp);
        long long take = gain[i];
        int j = i + 1;
        while (j < vals.size() && vals[j] <= vals[i] + 2)
            j++;
        take += solve(j, dp);
        dp[i] = max(skip, take);
        return dp[i];
    }

    long long maximumTotalDamage(vector<int> &power)
    {
        map<long long, long long> mp;
        for (int x : power)
            mp[x] += x;
        for (auto &p : mp)
        {
            vals.push_back(p.first);
            gain.push_back(p.second);
        }
        vector<long long> dp(vals.size() + 1, -1);
        return solve(0, dp);
    }
};
