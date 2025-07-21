#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int i : asteroids)
        {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && i < 0)
            {
                if (abs(i) > st.top())
                {
                    st.pop();
                }
                else if (abs(i) == st.top())
                {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                st.push(i);
            }
        }
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};
