#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        unordered_set<char> seen;
        int start = 0;
        int maxi = INT_MIN;
        for (int end = 0; end < s.size(); end++)
        {
            char c = s[end];
            while (seen.count(c))
            {
                seen.erase(s[start]);
                start++;
            }
            seen.insert(c);
            maxi = max(maxi, end - start + 1);
        }
        return maxi;
    }
};