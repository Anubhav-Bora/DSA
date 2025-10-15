#include <bits/stdc++.h>
using namespace std;

bool nextPerm(vector<string> &v, int l, int r)
{
    int i = r - 1;
    while (i > l && v[i - 1] >= v[i])
        i--;
    if (i <= l)
        return false;
    int j = r - 1;
    while (v[j] <= v[i - 1])
        j--;
    swap(v[i - 1], v[j]);
    reverse(v.begin() + i, v.begin() + r);
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> c;
    map<string, int> tot;
    for (int i = 0; i < n; i++)
    {
        string nm;
        int w;
        cin >> nm >> w;
        c.push_back({nm, w});
        tot[nm] += w;
    }

    int k;
    cin >> k;
    set<string> st;
    for (auto &p : c)
        st.insert(p.first);
    vector<string> ships(st.begin(), st.end());

    sort(ships.begin(), ships.end(), [&](string a, string b)
         {
        if(tot[a]!=tot[b]) return tot[a]>tot[b];
        return a<b; });

    vector<pair<int, int>> rng;
    int s = 0;
    for (int i = 1; i < (int)ships.size(); i++)
    {
        if (tot[ships[i]] != tot[ships[i - 1]])
        {
            rng.push_back({s, i});
            s = i;
        }
    }
    rng.push_back({s, (int)ships.size()});

    for (auto &r : rng)
        sort(ships.begin() + r.first, ships.begin() + r.second);

    vector<long long> fac;
    for (auto &r : rng)
    {
        int sz = r.second - r.first;
        long long f = 1;
        for (int i = 2; i <= sz; i++)
            f *= i;
        fac.push_back(f);
    }

    long long rem = k - 1;
    for (int g = 0; g < (int)rng.size(); g++)
    {
        int l = rng[g].first, r = rng[g].second;
        long long p = 1;
        for (int i = g + 1; i < (int)rng.size(); i++)
            p *= fac[i];
        long long skip = rem / p;
        rem %= p;
        for (long long x = 0; x < skip; x++)
            if (!nextPerm(ships, l, r))
                break;
    }

    map<string, int> pos;
    for (int i = 0; i < (int)ships.size(); i++)
        pos[ships[i]] = i + 1;

    long long ans = 0;
    for (int i = 0; i < (int)c.size(); i++)
    {
        int l = i + 1, s = pos[c[i].first], w = c[i].second;
        ans += (long long)w * (l + s);
    }

    cout << ans << "\n";
    for (int i = 0; i < (int)ships.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << ships[i];
    }
}
