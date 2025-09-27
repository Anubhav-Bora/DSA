#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += pow(-1, i) * i * i * i;
    }
    cout << sum << endl;
}