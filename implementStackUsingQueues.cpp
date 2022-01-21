#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1;

public:
    void push(int x)
    {
        this->q1.push(x);

        for (int i = 0; i < q1.size() - 1; i++) // s = 2-1--- 0<1---1<1
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack stk;
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    cout << "stk.push(2)" << endl;
    cout << "stk.push(3)" << endl;
    cout << "stk.push(4)" << endl;
    cout << "stk.push(5)" << endl;
    cout << "stk.top(): " << stk.top() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;
    cout << "stk.empty(): " << stk.empty() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;

    return 0;
}