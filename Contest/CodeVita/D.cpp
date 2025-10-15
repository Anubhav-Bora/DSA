#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<char>> grid;
int pearl, platinum, gold, diamond;

int getValue(char c)
{
    if (c == '$')
        return pearl;
    if (c == '*')
        return platinum;
    if (c == '%')
        return gold;
    if (c == '+')
        return diamond;
    return 0;
}

bool isStable(int row, int col)
{
    if (row == n - 1)
        return true;
    if (grid[row + 1][col] == '#')
        return true;
    return false;
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int startRow, startCol;
    cin >> startRow >> startCol;
    cin >> pearl >> platinum >> gold >> diamond;
    cin >> k;

    queue<vector<int>> q;
    set<vector<int>> visited;

    int startValue = getValue(grid[startRow][startCol]);
    q.push({startRow, startCol, 0, startValue});

    int maxTreasure = 0;
    if (startRow != n - 1)
        maxTreasure = startValue;

    while (!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();
        int row = curr[0], col = curr[1], steps = curr[2], treasure = curr[3];
        if (steps > k)
            continue;
        vector<int> state = {row, col, steps};
        if (visited.count(state))
            continue;
        visited.insert(state);

        for (int d : {-1, 1})
        {
            int nc = col + d;
            if (nc < 0 || nc >= m || grid[row][nc] == '#')
                continue;
            int newSteps = steps + 1;
            int newTreasure = treasure + getValue(grid[row][nc]);
            if (isStable(row, nc))
            {
                if (newSteps <= k && row != n - 1)
                    maxTreasure = max(maxTreasure, newTreasure);
                q.push({row, nc, newSteps, newTreasure});
            }
            else
            {
                int r = row + 1;
                while (r < n && !isStable(r - 1, nc))
                {
                    newTreasure += getValue(grid[r][nc]);
                    newSteps++;
                    r++;
                }
                if (newSteps <= k && r - 1 != n - 1)
                    maxTreasure = max(maxTreasure, newTreasure);
                q.push({r - 1, nc, newSteps, newTreasure});
            }
        }

        int r = row - 1;
        while (r >= 0 && grid[r][col] == '#')
            r--;
        if (r >= 0)
        {
            int newRow = r;
            int newSteps = steps + 1;
            int newTreasure = treasure + getValue(grid[newRow][col]);
            if (isStable(newRow, col))
            {
                if (newSteps <= k && newRow != n - 1)
                    maxTreasure = max(maxTreasure, newTreasure);
                q.push({newRow, col, newSteps, newTreasure});
            }
            else
            {
                r = newRow + 1;
                while (r < n && !isStable(r - 1, col))
                {
                    newTreasure += getValue(grid[r][col]);
                    newSteps++;
                    r++;
                }
                if (newSteps <= k && r - 1 != n - 1)
                    maxTreasure = max(maxTreasure, newTreasure);
                q.push({r - 1, col, newSteps, newTreasure});
            }
        }
    }

    cout << maxTreasure << endl;
    return 0;
}
