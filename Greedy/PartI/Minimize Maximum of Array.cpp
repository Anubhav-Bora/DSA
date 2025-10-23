#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int minimizeArrayValue(vector<int> &nums)
    {
        long long prefixSum = 0;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            int avg = (prefixSum + i) / (i + 1);
            // int avg = ceil((double)prefixSum / (i + 1));
            result = max(result, avg);
        }
        return result;
    }
};