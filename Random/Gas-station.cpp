#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalDiff = 0;
        int start = 0;
        int tank = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            totalDiff += diff;
            tank += diff;
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return totalDiff < 0 ? -1 : start;
    }
};