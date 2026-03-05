#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int mismatch = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != (i % 2 ? '1' : '0'))
                mismatch++;
        }
        return min(mismatch, (int)s.size() - mismatch);
    }
};

/*
Minimum Changes To Make Alternating Binary String:
Given a binary string s, return the minimum number of character flips to make s alternating.

An alternating string is a string where no two adjacent characters are equal.

For example, the binary string "010" is alternating, while the string "0100" is not alternating.
A character flip is replacing a '0' with a '1', or a '1' with a '0'.

Solution:
The idea is to count the number of mismatches for both possible alternating patterns: "010101
..." and "101010...". We can iterate through the string and compare each character with the expected character for both patterns. The minimum of the two mismatch counts will give us the answer.

example:
s = "0100"
For the pattern "0101...":
- s[0] = '0' (matches '0')
- s[1] = '1' (mismatches '1')
- s[2] = '0' (matches '0')
- s[3] = '0' (mismatches '1')
Mismatch count for "0101..." = 2

For the pattern "1010...":
- s[0] = '0' (matches '0')
- s[1] = '0' (mismatches '1')
- s[2] = '1' (matches '1')
- s[3] = '0' (mismatches '0')
Mismatch count for "1010..." = 2

The minimum of the two mismatch counts is 2, which is the answer.

we do min(`mismatch`, `s.size() - mismatch`) because if we have `mismatch` mismatches for one pattern, then the other pattern will have `s.size() - mismatch` mismatches. We want to choose the pattern that requires fewer flips, hence we take the minimum of the two counts.
*/