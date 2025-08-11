#include <bits/stdc++.h>
using namespace std;

#include <vector>

class Solution
{
public:
    void count(int i, int j, vector<vector<int>> &maze, vector<string> &res,
               vector<vector<bool>> &visited, string &ans, int n)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return;
        if (maze[i][j] == 0 || visited[i][j])
            return;
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(ans);
            return;
        }

        visited[i][j] = true;
        ans.push_back('D');
        count(i + 1, j, maze, res, visited, ans, n);
        ans.pop_back();

        ans.push_back('U');
        count(i - 1, j, maze, res, visited, ans, n);
        ans.pop_back();

        ans.push_back('R');
        count(i, j + 1, maze, res, visited, ans, n);
        ans.pop_back();

        ans.push_back('L');
        count(i, j - 1, maze, res, visited, ans, n);
        ans.pop_back();

        visited[i][j] = false;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> res;
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return res;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string ans;
        count(0, 0, maze, res, visited, ans, n);

        sort(res.begin(), res.end());

        return res;
    }
};