#include <bits/stdc++.h>
using namespace std;

double filling_rate(const string &sub)
{
    int n = (int)sub.size();
    if (n < 3)
        return 0;
    if (sub.front() != 't' || sub.back() != 't')
        return 0;

    int count_t = 0;
    for (char c : sub)
        if (c == 't')
            count_t++;

    return double(count_t - 2) / double(n - 2);
}

int main()
{
    string S;
    cin >> S;

    double max_rate = 0;
    int n = (int)S.size();

    for (int start = 0; start < n; start++)
    {
        for (int end = start + 2; end < n; end++)
        {
            string sub = S.substr(start, end - start + 1);
            double rate = filling_rate(sub);
            if (rate > max_rate)
                max_rate = rate;
        }
    }

    cout << fixed << max_rate << "\n";

    return 0;
}
