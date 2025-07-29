#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;

    void sort();
};

// Helper function to insert elements in sorted order
void insertSorted(stack<int> &s, int x)
{
    if (s.empty() || x >= s.top())
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}

// Sort function for the stack
void SortedStack::sort()
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();

    sort(); // Recursive call
    insertSorted(s, x);
}

// Helper function to print stack from top to bottom
void printStack(stack<int> s)
{
    vector<int> temp;
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    for (int x : temp)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    SortedStack ss;

    // Push elements in random order
    ss.s.push(3);
    ss.s.push(1);
    ss.s.push(4);
    ss.s.push(2);

    cout << "Original stack (top to bottom): ";
    printStack(ss.s);

    ss.sort();

    cout << "Sorted stack (top to bottom): ";
    printStack(ss.s);

    return 0;
}
