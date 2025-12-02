#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<int, int> mp;
        for (auto &x : points)
        {
            mp[x[1]]++;
        }
        long long edge = 0;
        long long sum = 0;
        long long ans = 0;
        const int mod = 1e9 + 7;

        for (const auto &kv : mp)
        {
            int y = kv.second;
            edge = (long long)y * (y - 1) / 2;
            ans = (ans + edge * sum) % mod;
            sum = (sum + edge) % mod;
        }
        return ans;
    }
};