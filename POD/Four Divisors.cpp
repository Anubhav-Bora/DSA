#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int x : nums)
        {
            int cnt = 0;
            for (int d = 1; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    cnt++;
                    if (d != x / d)
                        cnt++;
                }
            }
            mp[x] = cnt;
        }

        int sum = 0;
        for (int x : nums)
        {
            if (mp[x] == 4)
            {
                for (int d = 1; d * d <= x; d++)
                {
                    if (x % d == 0)
                    {
                        sum += d;
                        if (d != x / d)
                            sum += x / d;
                    }
                }
            }
        }
        return sum;
    }
};
