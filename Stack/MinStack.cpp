#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {}

    void push(int val)
    {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        if (!mainStack.empty())
        {
            mainStack.pop();
            minStack.pop();
        }
    }

    int top()
    {
        return mainStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Min: " << obj->getMin() << endl; // -3
    obj->pop();
    cout << "Top: " << obj->top() << endl;    // 0
    cout << "Min: " << obj->getMin() << endl; // -2

    delete obj;
    return 0;
}
