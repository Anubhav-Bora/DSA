#include <bits/stdc++.h>
using namespace std;
void convert(string S)
{
    if (S == "red")
        cout << "SSS";
    else if (S == "green")
        cout << "MMM";
    else if (S == "blue")
        cout << "FFF";
    else
        cout << "Unknown";
}

int main()
{
    string S;
    cin >> S;
    convert(S);
}