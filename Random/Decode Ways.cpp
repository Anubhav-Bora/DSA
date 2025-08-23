#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int res(string s, int i, int size, vector<int> &dp)
    {
        if (i >= size)
        {
            return 1;
        }
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        // one digit
        int count = res(s, i + 1, size, dp);
        // 2 digit
        if (i + 1 < size)
        {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
            {
                count += res(s, i + 2, size, dp);
            }
        }
        return dp[i] = count;
    }
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        int size = s.size();
        vector<int> dp(size, -1);
        return res(s, 0, size, dp);
    }
};