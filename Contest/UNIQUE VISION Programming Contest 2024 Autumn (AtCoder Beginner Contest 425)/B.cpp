#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), P(N, -1);
    set<int> used;
    bool ok = true;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        if (A[i] != -1)
        {
            if (used.count(A[i]))
                ok = false;
            used.insert(A[i]);
            P[i] = A[i];
        }
    }
    if (!ok)
    {
        cout << "No\n";
        return 0;
    }
    vector<int> unused;
    for (int i = 1; i <= N; ++i)
    {
        if (!used.count(i))
            unused.push_back(i);
    }
    int idx = 0;
    for (int i = 0; i < N; ++i)
    {
        if (P[i] == -1)
        {
            P[i] = unused[idx++];
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < N; ++i)
        cout << P[i] << " ";
    cout << "\n";
    return 0;
}