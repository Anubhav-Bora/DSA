#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> store;
        int n = s.size();
        int i = 0;

        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n)
                break;

            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            store.push_back(s.substr(i, j - i));
            i = j;
        }

        reverse(store.begin(), store.end());

        string ans;
        for (int k = 0; k < store.size(); k++)
        {
            ans += store[k];
            if (k < store.size() - 1)
            {
                ans += ' ';
            }
        }

        return ans;
    }
};
