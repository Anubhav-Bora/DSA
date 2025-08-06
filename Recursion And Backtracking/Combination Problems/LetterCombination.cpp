#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combi(string &digits, int index, unordered_map<char, string> &phoneMap, vector<char> &current, vector<string> &res)
    {
        if (index == digits.size())
        {
            res.push_back(string(current.begin(), current.end()));
            return;
        }
        string letters = phoneMap[digits[index]];
        for (char ch : letters)
        {
            current.push_back(ch);
            combi(digits, index + 1, phoneMap, current, res);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<char> current;
        vector<string> res;
        if (digits.empty())
            return res;

        combi(digits, 0, phoneMap, current, res);
        return res;
    }
};
