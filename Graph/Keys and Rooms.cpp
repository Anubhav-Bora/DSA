#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (visited[curr])
                continue;
            visited[curr] = true;
            for (int keys : rooms[curr])
            {
                if (!visited[keys])
                {
                    q.push(keys);
                }
            }
        }
        for (bool i : visited)
        {
            if (!i)
                return false;
        }
        return true;
    }
};