#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> ZeroNeed(n);

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            ZeroNeed[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            int req = n - 1 - i;
            int j = i;

            while (j < n && ZeroNeed[j] < req)
                j++;

            if (j == n)
                return -1;

            while (j > i)
            {
                swap(ZeroNeed[j], ZeroNeed[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};

// Let me Explain Todays POD where we have to count the number of steps we need in order to make the upper part of the diagonal of a 2D or GRID 0
/* The core is that in order to achieve each row should contain exactly n-1-i zeros
So first we will count the number of zeros present at last of each row and store it in a vector
Next we have to check are we matching the required zeros as required if not we go downward from top row to bottom , in  case we reach the end it means it is not possible and return -1
otherwise while (j>i) where i is the current row and j is the row we need to swap with i . On each swap do swaps++ and return swap. Return swaps

IT IS A GREEDY PROBLEM
*/
