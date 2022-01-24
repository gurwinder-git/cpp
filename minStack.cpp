#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

class MinStack
{
public:
    stack<int> minStk;
    stack<int> stk;

    MinStack()
    {
        minStk.push(INT_MAX);
    }

    void push(int val)
    {
        stk.push(val);
        if (val <= minStk.top())
            minStk.push(val);
    }

    void pop()
    {
        if (minStk.top() == stk.top())
            minStk.pop();

        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};
int main()
{
    MinStack minStk;

    minStk.push(9);
    minStk.push(3);
    minStk.push(-3);
    minStk.push(2);
    minStk.push(6);
    minStk.push(-10);
    cout << minStk.getMin() << endl;
    minStk.pop();
    cout << minStk.getMin() << endl;
    minStk.pop();
    cout << minStk.getMin() << endl;
    minStk.pop();
    cout << minStk.getMin() << endl;
    minStk.pop();
    cout << minStk.getMin() << endl;
    return 0;
}