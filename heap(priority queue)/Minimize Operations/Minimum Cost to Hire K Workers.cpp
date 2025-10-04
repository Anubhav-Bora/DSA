#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++)
        {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        long long sumQual = 0;
        double minCost = 1e18;

        for (auto &w : workers)
        {
            double ratio = w.first;
            int q = w.second;
            pq.push(q);
            sumQual += q;
            if (pq.size() > k)
            {
                sumQual -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                double cost = ratio * sumQual;
                if (cost < minCost)
                    minCost = cost;
            }
        }
        return minCost;
    }
};
