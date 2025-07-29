#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int towerOfHanoi(int n, int from, int to, int aux)
    {
        if (n == 1)
            return 1;
        return 2 * towerOfHanoi(n - 1, from, to, aux) + 1;
    }
};