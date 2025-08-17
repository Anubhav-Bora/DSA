#include <bits/stdc++.h>
using namespace std;

void solution(int N, int Q, vector<int> A, vector<int> B, int maxi)
{
}

int main()
{

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    int maxi = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] > maxi)
            maxi = A[i];
    }
    vector<int> B(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> B[i];
    }
    solution(N, Q, A, B, maxi);

    return 0;
}
