#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0;
        int count = 0;
        for (int x : nums)
        {
            if (x % 2 != 0)
                prefix++;
            count += freq[prefix - k];
            freq[prefix]++;
        }
        return count;
    }
};