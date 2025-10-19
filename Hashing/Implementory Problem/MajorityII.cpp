#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        set<int> res;
        for (auto x : nums)
        {
            freq[x]++;
            if (freq[x] > n / 3)
            {
                res.insert(x);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
