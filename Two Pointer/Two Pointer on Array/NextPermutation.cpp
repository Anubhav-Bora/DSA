#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int high = nums.size() - 2;
        while (high >= 0 && nums[high] >= nums[high + 1])
        {
            high--;
        }
        if (high >= 0)
        {
            for (int i = nums.size() - 1; i > high; i--)
            {
                if (nums[i] > nums[high])
                {
                    swap(nums[high], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + high + 1, nums.end());
    }
};