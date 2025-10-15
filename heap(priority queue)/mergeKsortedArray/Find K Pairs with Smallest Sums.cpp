using namespace std;
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < min((int)nums1.size(), k); i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        while (!pq.empty() && res.size() < k)
        {
            auto c = pq.top();
            pq.pop();
            int i = c[1];
            int j = c[2];
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size())
            {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return res;
    }
};