#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int count = 0;
        int sum = 0;
        int target = threshold * k;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        if (sum >= target)
            count++;

        for (int i = k; i < arr.size(); i++)
        {
            sum += arr[i] - arr[i - k];
            if (sum >= target)
                count++;
        }
        return count;
    }
};