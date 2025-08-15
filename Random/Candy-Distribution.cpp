#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_map<int, int> freq;
        int n = candyType.size() / 2;
        for (int i = 0; i < candyType.size(); i++)
        {
            freq[candyType[i]]++;
        }
        int mini;
        int x = freq.size();
        for (int i = 0; i < x; i++)
        {
            mini = min(n, x);
        }
        return mini;
    }
};