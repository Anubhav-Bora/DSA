#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reformatDate(string date)
    {
        int length = date.size();
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        string answer = "";
        answer += date.substr(length - 4, 4);
        answer += "-";

        if (length == 13)
        {
            answer += months[date.substr(5, 3)];
            answer += "-";
            answer += date.substr(0, 2);
        }
        else
        {
            answer += months[date.substr(4, 3)];
            answer += "-";
            answer += "0";
            answer += date.substr(0, 1);
        }
        return answer;
    }
};