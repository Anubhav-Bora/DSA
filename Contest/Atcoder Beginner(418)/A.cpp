#include <bits/stdc++.h>
using namespace std;

string valid(int N, string S)
{
    if (N < 3)
        return "No";
    int i = S.size() - 1;
    if (S[i] == 'a' && S[i - 1] == 'e' && S[i - 2] == 't')
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main()
{
    int N;
    string S;
    cin >> N >> S;
    string ans = valid(N, S);
    cout << ans << "\n";
    return 0;
}
