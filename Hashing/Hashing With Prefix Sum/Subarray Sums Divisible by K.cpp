#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0, count = 0;

        for (int x : nums)
        {
            prefix += x;
            int rem = ((prefix % k) + k) % k;
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};
