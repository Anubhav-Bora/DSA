#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        s += s;
        int ans = INT_MAX;
        int l = 0;
        int pattern1 = 0; // 10101
        int pattern2 = 0; // 01010
        for (int i = 0; i < n * 2; i++)
        {
            if (s[i] != (i % 2 ? '0' : '1'))
                pattern1++;
            if (s[i] != (i % 2 ? '1' : '0'))
                pattern2++;
            if (i - l + 1 > n)
            {
                if (s[l] != (l % 2 ? '0' : '1'))
                    pattern1--;
                if (s[l] != (l % 2 ? '1' : '0'))
                    pattern2--;
                l++;
            }
            if (i - l + 1 == n)
            {
                ans = min(ans, min(pattern1, pattern2));
            }
        }
        return ans;
    }
};