#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};
        for (char c : tasks)
            freq[c - 'A']++;
        priority_queue<int> pq;
        for (int f : freq)
            if (f > 0)
                pq.push(f);
        int time = 0;
        while (!pq.empty())
        {
            int cycle = n + 1;
            vector<int> tmp;
            int taskCount = 0;
            while (cycle-- && !pq.empty())
            {
                int cnt = pq.top();
                pq.pop();
                if (--cnt > 0)
                    tmp.push_back(cnt);
                taskCount++;
            }
            for (int cnt : tmp)
                pq.push(cnt);
            time += pq.empty() ? taskCount : n + 1;
        }
        return time;
    }
};
