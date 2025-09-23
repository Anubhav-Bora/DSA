#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto x : points)
        {
            int a = x[0];
            int b = x[1];
            int dist = a * a + b * b;
            pq.push({dist, {a, b}});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            auto [p, cord] = pq.top();
            pq.pop();
            res.push_back({cord.first, cord.second});
        }
        return res;
    }
};