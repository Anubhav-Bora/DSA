#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x = 0;
        while (n > 2)
        {
            int m1 = n / 3;
            x += m1;
            n -= 2 * m1;
        }
        cout << x << endl;
    }
}
