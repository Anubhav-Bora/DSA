#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        vector<int> ls(nums.size(), 0);
        vector<int> rs(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++)
        {
            ls[i] = ls[i - 1] + nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            rs[i] = rs[i + 1] + nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = abs(ls[i] - rs[i]);
        }
        return ans;
    }
};