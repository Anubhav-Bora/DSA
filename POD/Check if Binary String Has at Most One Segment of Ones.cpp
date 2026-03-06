#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '1' && s[i - 1] == '0')
                return false;
        }
        return true;
    }
};

/*
Check if Binary String Has at Most One Segment of Ones
Given a binary string s, return true if all the 1's in s are part of a single contiguous segment. Otherwise, return false.
A segment is a contiguous sequence of characters within a string.
Solution:
The idea is to iterate through the string and check for any occurrence of '1' that is immediately followed by '0' and then another '1'. If such a pattern is found, it means there are multiple segments of '1's, and we can return false. If we finish iterating through the string without finding such a pattern, we can return true.
Example:
s = "11000"
- s[0] = '1' (matches '1')
- s[1] = '1' (matches '1')
- s[2] = '0' (mismatches '0')
- s[3] = '0' (matches '0')
- s[4] = '0' (matches '0')

*/