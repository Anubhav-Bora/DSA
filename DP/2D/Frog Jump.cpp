#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sol(int i, vector<int> &stones, int k, unordered_map<long long, int> &dp)
    {
        if (i == stones.size() - 1)
            return true;

        long long key = ((long long)i << 32) | k;
        if (dp.count(key))
            return dp[key];

        for (int step = k - 1; step <= k + 1; step++)
        {
            if (step <= 0)
                continue;

            int nextPos = stones[i] + step;
            auto it = lower_bound(stones.begin(), stones.end(), nextPos);

            if (it != stones.end() && *it == nextPos)
            {
                if (sol(it - stones.begin(), stones, step, dp))
                    return dp[key] = 1;
            }
        }

        return dp[key] = 0;
    }

    bool canCross(vector<int> &stones)
    {
        if (stones.size() > 1 && stones[1] != 1)
            return false;
        unordered_map<long long, int> dp;
        return sol(1, stones, 1, dp);
    }
};
