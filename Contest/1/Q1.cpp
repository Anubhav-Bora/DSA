#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cin >> X;

    bool found = false;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == X)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
