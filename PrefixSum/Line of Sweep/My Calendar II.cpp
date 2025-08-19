#include <bits/stdc++.h>
using namespace std;
class MyCalendarTwo
{
public:
    map<int, int> diff;
    MyCalendarTwo() {}

    bool book(int startTime, int endTime)
    {
        diff[startTime]++;
        diff[endTime]--;
        int active = 0;
        for (auto &it : diff)
        {
            active += it.second;
            if (active > 2)
            {
                // rollback
                diff[startTime]--;
                diff[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */