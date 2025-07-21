#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int low = 0;
        vector<int> ans;
        int high = s.length();
        for (char c : s)
        {
            if (c == 'I')
            {
                ans.push_back(low++);
            }
            else
            {
                ans.push_back(high--);
            }
        }
        ans.push_back(low);
        return ans;
    }
};