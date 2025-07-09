#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        const int MAX = 10001;
        vector<bool> visited(MAX, false);

        queue<pair<int, int>> q;
        q.push({x, 0});

        while (!q.empty())
        {
            int curr = q.front().first;
            int count = q.front().second;
            q.pop();

            if (curr == y)
                return count;
            if (curr < 0 || curr >= MAX || visited[curr])
                continue;

            visited[curr] = true;

            if (curr % 11 == 0)
                q.push({curr / 11, count + 1});
            if (curr % 5 == 0)
                q.push({curr / 5, count + 1});
            q.push({curr + 1, count + 1});
            q.push({curr - 1, count + 1});
        }

        return -1;
    }
};
