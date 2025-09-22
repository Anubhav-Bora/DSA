#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int day = 0;
        int count = 0;
        int n = events.size();
        while (i < n || !pq.empty())
        {
            if (pq.empty())
            {
                day = events[i][0]; // move to next day
            }
            while (i < n && events[i][0] <= day)
            {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }
            while (!pq.empty())
            {
                pq.pop();
                count++;
            }
            day++;
        }
        return count;
    }
};