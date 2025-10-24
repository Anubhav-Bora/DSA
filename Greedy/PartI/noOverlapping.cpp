#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int count = 0;
        int end = INT_MIN;
        for (auto &x : intervals)
        {
            if (end <= x[0])
            {
                end = x[1];
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};