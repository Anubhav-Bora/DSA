#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void permut(vector<int> &nums, int l, int &count, int n)
    {
        if (l == n)
        {
            count++;
            return;
        }
        for (int i = l; i < n; i++)
        {
            swap(nums[l], nums[i]);

            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
            {
                permut(nums, l + 1, count, n);
            }

            swap(nums[l], nums[i]);
        }
    }

    int countArrangement(int n)
    {
        int count = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
        }
        permut(nums, 0, count, n);
        return count;
    }
};
