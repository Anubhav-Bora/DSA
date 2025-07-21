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
    obj->push(5);
    obj->push(3);
    obj->push(7);
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    delete obj;
    return 0;
}
