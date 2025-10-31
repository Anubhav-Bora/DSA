#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        int count = 0;
        int maxi = INT_MIN;
        unordered_map<string, int> freq;
        int ans = 0;
        for (int i = 0; i + minSize <= s.size(); i++)
        {
            string sub = s.substr(i, minSize);
            unordered_set<char> st(sub.begin(), sub.end());
            if (st.size() <= maxLetters)
            {
                freq[sub]++;
                ans = max(ans, freq[sub]);
            }
        }
        return ans;
    }
};