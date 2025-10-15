#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> a(24);
    for (int i = 0; i < 24; i++)
        cin >> a[i];

    int cor[8][3] = {
        {2, 4, 17}, {3, 5, 20}, {0, 16, 12}, {1, 13, 21}, {6, 8, 18}, {7, 9, 23}, {10, 14, 19}, {11, 15, 22}};

    set<string> ud;
    for (int i = 0; i < 4; i++)
        ud.insert(a[i]);
    for (int i = 8; i < 12; i++)
        ud.insert(a[i]);

    int t = -1;
    for (int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
            if (ud.count(a[cor[i][j]]))
                cnt++;
        if (cnt >= 2)
        {
            t = i;
            break;
        }
    }

    if (t == -1)
    {
        int sum = 0;
        vector<int> o(8, 0);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ud.count(a[cor[i][j]]))
                {
                    o[i] = j;
                    break;
                }
            }
            sum += o[i];
        }
        for (int i = 0; i < 8; i++)
        {
            if (o[i] != 0 && (sum - o[i]) % 3 == 0)
            {
                t = i;
                break;
            }
        }
    }

    if (t == -1)
        t = 0;

    vector<string> res;
    for (int j = 0; j < 3; j++)
        res.push_back(a[cor[t][j]]);
    sort(res.begin(), res.end());
    cout << res[0] << res[1] << res[2] << endl;

    return 0;
}
