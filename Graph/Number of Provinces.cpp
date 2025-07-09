#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int city, vector<bool> &visited, vector<vector<int>> &list)
    {
        queue<int> q;
        q.push(city);
        visited[city] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int i : list[curr])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> list(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    list[i].push_back(j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                bfs(i, visited, list);
            }
        }
        return count;
    }
};