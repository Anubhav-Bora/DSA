#include <bits/stdc++.h>
using namespace std;
map<char, vector<char>> toggles = {
    {'0', {'8'}}, {'1', {'7'}}, {'3', {'9'}}, {'5', {'6', '9'}}, {'6', {'5', '8'}}, {'7', {'1'}}, {'8', {'0', '6', '9'}}, {'9', {'3', '5', '8'}}};
int calculation(int h1, int m1, int h2, int m2, int X, int Y)
{
    int hourDiff = abs(h1 - h2);
    hourDiff = min(hourDiff, 12 - hourDiff);
    int minuteDiff = abs(m1 - m2);
    minuteDiff = min(minuteDiff, 60 - minuteDiff);
    return hourDiff * 60 * X + minuteDiff * Y;
}
int main()
{
    string time;
    cin >> time;
    int X, Y;
    cin >> X >> Y;
    string hour = time.substr(0, 2);
    string minute = time.substr(3, 2);
    string finalTime = hour + minute;
    int minCost = INT_MAX;
    string best = "";
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            continue;
        char current = finalTime[i];
        if (toggles.find(current) == toggles.end())
            continue;
        for (char x : toggles[current])
        {
            string newTime = finalTime;
            newTime[i] = x;
            int newHour = stoi(newTime.substr(0, 2));
            int newMinute = stoi(newTime.substr(2, 2));
            if (newHour < 1 || newHour > 12)
                continue;
            if (newMinute < 0 || newMinute > 59)
                continue;
            int h = stoi(hour);
            int m = stoi(minute);
            int cost = calculation(h, m, newHour, newMinute, X, Y);
            if (cost < minCost || (cost == minCost && best.empty()) ||
                (cost == minCost && newTime < best.substr(0, 2) + best.substr(3, 2)))
            {
                minCost = cost;
                best = newTime.substr(0, 2) + ":" + newTime.substr(2, 2);
            }
        }
    }

    if (best.empty())
        cout << "No closest valid time possible";
    else
        cout << best;
}