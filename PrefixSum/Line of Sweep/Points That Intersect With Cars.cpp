#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int maxElement;
        for (auto &car : nums)
        {
            maxElement = max(maxElement, car[1]);
        }
        vector<int> diff(maxElement + 2, 0);
        for (auto &car : nums)
        {
            int l = car[0];
            int r = car[1];
            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        int active = 0;
        int count = 0;
        for (int i = 1; i <= maxElement; i++)
        {
            active += diff[i];
            if (active > 0)
            {
                count++;
            }
        }
        return count;
    }
};