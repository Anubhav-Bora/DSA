#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x, y;
    cin >> x >> y;
    if (x == y || x == "Serval" && y == "Ocelot" || x == "Lynx" && y == "Serval" || x == "Lynx" && y == "Ocelot")
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}