#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int start = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        int maxi = -1;
        int currSum = 0;
        if (target == 0)
            return nums.size();
        if (target < 0)
            return -1;
        for (int end = 0; end < nums.size(); end++)
        {
            currSum += nums[end];
            while (currSum > target && start <= end)
            {
                currSum -= nums[start];
                start++;
            }
            if (currSum == target)
            {
                maxi = max(maxi, end - start + 1);
            }
        }
        return (maxi == -1) ? -1 : (nums.size() - maxi);
    }
};