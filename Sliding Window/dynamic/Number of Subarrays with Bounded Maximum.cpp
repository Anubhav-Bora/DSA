#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int start = 0;
        int count = 0;
        int valid = -1;
        int invalid = -1;
        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] > right)
            {
                invalid = end;
            }
            if (nums[end] >= left && nums[end] <= right)
            {
                valid = end;
            }
            count += max(0, valid - invalid);
        }
        return count;
    }
};