#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int even = 0;
        int odd = 1;
        for (auto i : nums)
        {
            if (i % 2 == 0)
            {
                ans[even] = i;
                even += 2;
            }
            else
            {
                ans[odd] = i;
                odd += 2;
            }
        }
        return ans;
    }
};