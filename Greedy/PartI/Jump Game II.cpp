#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jump = 0;
        int farthest = 0;
        int currEnd = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (currEnd == i)
            {
                jump++;
                currEnd = farthest;
            }
        }
        return jump;
    }
};