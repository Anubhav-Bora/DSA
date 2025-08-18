#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int maxElement = INT_MIN;
        for (auto &d : trips)
        {
            maxElement = max(d[2], maxElement);
        }
        vector<int> diff(maxElement + 2, 0);
        for (auto &d : trips)
        {
            int l = d[1];
            int r = d[2];
            diff[l] += d[0];
            diff[r] -= d[0];
        }
        int active = 0;
        for (int i = 0; i < maxElement; i++)
        {
            active += diff[i];
            if (active > capacity)
            {
                return false;
            }
        }
        return true;
    }
};