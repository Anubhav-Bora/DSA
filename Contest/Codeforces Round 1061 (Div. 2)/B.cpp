#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<long long> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        for (long long x : queries)
        {
            long long seconds = 0;
            int pos = 0;

            while (x > 0)
            {
                if (s[pos] == 'A')
                {
                    int countA = 0;
                    int start = pos;
                    while (s[pos] == 'A')
                    {
                        countA++;
                        pos = (pos + 1) % n;
                        if (pos == start)
                            break;
                    }

                    if (x <= countA)
                    {
                        seconds += x;
                        break;
                    }
                    else
                    {
                        x -= countA;
                        seconds += countA;
                        continue;
                    }
                }
                else
                {
                    x /= 2;
                    seconds++;
                    pos = (pos + 1) % n;
                }
            }

            cout << seconds << "\n";
        }
    }
}
