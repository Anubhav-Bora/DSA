#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sum(int value, int count)
    {
        if (count <= value)
        {

            return 1LL * (value + (value - count + 1)) * count / 2;
        }
        else
        {
            int ones = count - value;
            return 1LL * value * (value + 1) / 2 + ones;
        }
    }

    bool isValid(int n, int index, int maxSum, int mid)
    {
        int leftCount = index;
        int rightCount = n - index - 1;

        long long leftSum = sum(mid - 1, leftCount);
        long long rightSum = sum(mid - 1, rightCount);

        long long total = leftSum + rightSum + mid;

        return total <= 1LL * maxSum;
    }

    int maxValue(int n, int index, int maxSum)
    {
        int low = 1;
        int high = maxSum;
        int answer = 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isValid(n, index, maxSum, mid))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};
