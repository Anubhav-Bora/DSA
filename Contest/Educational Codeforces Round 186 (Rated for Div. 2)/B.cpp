#include <bits/stdc++.h>
using namespace std;

int ans(int a, int b, bool white)
{
    int layers = 0;
    int layerSize = 1;
    bool color = white;
    while (true)
    {
        if (color)
        {
            if (a < layerSize)
            {
                break;
            }
            else
            {
                a -= layerSize;
            }
        }
        else
        {
            if (b < layerSize)
            {
                break;
            }
            else
            {
                b -= layerSize;
            }
        }
        layers++;
        layerSize = 2 * layerSize;
        color = !color;
    }
    return layers;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << max(ans(a, b, true), ans(a, b, false)) << "\n";
    }
}