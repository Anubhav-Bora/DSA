#
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> pq;
        for (auto num : arr)
        {
            int d = abs(num - x);
            pq.push({d, num});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            res.push_back(y);
        }
        sort(res.begin(), res.end());
        return res;
    }
};