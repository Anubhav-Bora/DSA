#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        int n = nums.size();
        int modulo = 1000000007;
        unordered_map<int, int> suffix;
        unordered_map<int, int> prefix;
        if (n < 3)
        {
            return 0;
        }
        for (int i : nums)
        {
            suffix[i]++;
        }
        long long count = 0;
        for (int j = 0; j < n; j++)
        {
            int x = nums[j];
            suffix[x]--;
            long long target = nums[j] * 2;
            long count_suffix = suffix.count(target) ? suffix.at(target) : 0;
            long count_prefix = prefix.count(target) ? prefix.at(target) : 0;
            long long contri = count_suffix * count_prefix;
            count = contri + count;
            prefix[x]++;
        }
        return count % modulo;
    }
};