#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> head;
        priority_queue<int, vector<int>, greater<int>> tail;
        for (int i = 0; i < candidates; i++)
        {
            head.push(costs[i]);
        }
        for (int i = n - 1; i >= n - candidates && i >= candidates; i--)
        {
            tail.push(costs[i]);
        }

        long long total = 0;
        int nextHead = candidates;
        int nextTail = n - candidates - 1;
        for (int i = 0; i < k; i++)
        {
            if (tail.empty() || (!head.empty() && head.top() <= tail.top()))
            {
                total += head.top();
                head.pop();
                if (nextHead <= nextTail)
                {
                    head.push(costs[nextHead]);
                    nextHead++;
                }
            }
            else
            {
                total += tail.top();
                tail.pop();
                if (nextHead <= nextTail)
                {
                    tail.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return total;
    }
};