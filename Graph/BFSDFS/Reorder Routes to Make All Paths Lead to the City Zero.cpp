#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int node, int &count, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neigh : adj[node])
        {
            int next = abs(neigh);
            if (!visited[next])
            {
                if (neigh > 0)
                {
                    count++;
                }

                dfs(next, count, adj, visited);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int count = 0;
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        for (auto &conec : connections)
        {
            int u = conec[0];
            int v = conec[1];
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
        return dfs(0, count, adj, visited);
    }
};