#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += cardPoints[i];
        }
        if (n == k)
            return sum;

        int window = n - k;
        int minSum = INT_MAX;
        int curr = 0;

        // first window
        for (int i = 0; i < window; i++)
        {
            curr += cardPoints[i];
        }
        minSum = curr;
        // remaining
        for (int i = window; i < n; i++)
        {
            curr += cardPoints[i] - cardPoints[i - window];
            minSum = min(minSum, curr);
        }
        return sum - minSum;
    }
};