#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        long long ans = LLONG_MIN;
        long long prefix = 0;
        vector<long long> best(k, LLONG_MAX);
        best[0] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            int rem = (i + 1) % k;
            if (best[rem] != LLONG_MAX)
            {
                ans = max(ans, prefix - best[rem]);
            }
            best[rem] = min(best[rem], prefix);
        }

        return ans;
    }
};
