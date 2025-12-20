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
        string s;
        cin >> s;
        int space = 0;
        int maxSpace = 0;
        int count = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                space++;
                maxSpace = max(maxSpace, space);
                count++;
            }
            else
            {
                space = 0;
            }
        }
        cout << count - maxSpace << endl;
    }
}