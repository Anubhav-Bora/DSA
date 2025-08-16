#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    vector<int> A;
    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        else
        {
            int smallest = A[0];
            int idx = 0;
            for (int i = 1; i < A.size(); i++)
            {
                if (A[i] < smallest)
                {
                    smallest = A[i];
                    idx = i;
                }
            }
            cout << smallest << endl;
            A.erase(A.begin() + idx);
        }
    }
}