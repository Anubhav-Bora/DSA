#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> res(n);
        int index = 0;
        for (int i : nums)
        {
            if (i < pivot)
                res[index++] = i;
        }
        for (int i : nums)
        {
            if (i == pivot)
                res[index++] = i;
        }
        for (int i : nums)
        {
            if (i > pivot)
                res[index++] = i;
        }
        return res;
    }
};