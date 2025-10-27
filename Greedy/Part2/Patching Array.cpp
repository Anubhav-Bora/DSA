#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, long long n)
    {
        long long miss = 1;
        int i = 0, patches = 0;

        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i];
                i++;
            }
            else
            {
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};
