#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int countOne = 0;
        int countZero = 0;
        vector<int> posOne;
        vector<int> posZero;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                countOne++;
                posOne.push_back(i + 1);
            }
            else
            {
                countZero++;
                posZero.push_back(i + 1);
            }
        }
        
        if (countOne == 0)
        {
            cout << 0 << "\n";
            cout << "\n";
        }
        else if (countOne % 2 == 0)
        {
            cout << countOne << "\n";
            for (int i = 0; i < (int)posOne.size(); i++)
                cout << posOne[i] << " ";
            cout << "\n";
        }
        else
        {
            if (n % 2 == 0)
            {
                cout << countZero << "\n";
                for (int i = 0; i < (int)posZero.size(); i++)
                    cout << posZero[i] << " ";
                cout << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}