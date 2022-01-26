#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

// O(n) extra space
// class MinStack
// {
// public:
//     stack<int> minStk;
//     stack<int> stk;

//     MinStack()
//     {
//         minStk.push(INT_MAX);
//     }

//     void push(int val)
//     {
//         stk.push(val);
//         if (val <= minStk.top())
//             minStk.push(val);
//     }

//     void pop()
//     {
//         if (minStk.top() == stk.top())
//             minStk.pop();

//         stk.pop();
//     }

//     int top()
//     {
//         return stk.top();
//     }

//     int getMin()
//     {
//         return minStk.top();
//     }
// };

// O(1) extra space
class MinStack
{
public:
    long minVal;
    stack<long> stk;

    MinStack()
    {
        minVal = INT_MAX;
    }

    void push(int val)
    {
        if (val < minVal)
        {
            long v = val;
            long fakeVal = v + (v - minVal);
            stk.push(fakeVal);
            minVal = val;
        }
        else
        {
            stk.push(val);
        }
    }

    void pop()
    {
        if (stk.top() < minVal)
        {
            minVal = (2 * minVal) - stk.top();
        }
        stk.pop();
    }

    int top()
    {
        if (stk.top() >= minVal)
            return stk.top();
        else
            return minVal;
    }

    int getMin()
    {
        return minVal;
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