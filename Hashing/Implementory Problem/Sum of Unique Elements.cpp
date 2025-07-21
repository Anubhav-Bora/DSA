#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        int sum = 0;
        for (auto &entry : freq)
        {
            if (entry.second == 1)
            {
                sum += entry.first;
            }
        }

        return sum;
    }
};