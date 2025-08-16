#include <bits/stdc++.h>
using namespace std;
long long minMeetingTime(vector<long long> &R, vector<long long> &C)
{
    long long low = 0, high = 1e9;
    while (low < high)
    {
        long long mid = (low + high) / 2;
        long long rL = LLONG_MIN, rR = LLONG_MAX;
        long long cL = LLONG_MIN, cR = LLONG_MAX;
        for (int i = 0; i < R.size(); i++)
        {
            rL = max(rL, R[i] - mid);
            rR = min(rR, R[i] + mid);
            cL = max(cL, C[i] - mid);
            cR = min(cR, C[i] + mid);
        }
        if (rL <= rR && cL <= cR)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int N;
    cin >> N;
    vector<long long> R(N), C(N);
    for (int i = 0; i < N; i++)
        cin >> R[i] >> C[i];
    cout << minMeetingTime(R, C) << "\n";
}