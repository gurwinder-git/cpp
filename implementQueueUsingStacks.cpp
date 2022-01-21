#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    void push(int x)
    {
        this->input.push(x);
    }

    int pop()
    {
        int val;
        if (!output.empty())
        {
            val = output.top();
            output.pop();
            return val;
        }

        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        val = output.top();
        output.pop();
        return val;
    }

    int peek()
    {
        if (!output.empty())
        {
            return output.top();
        }

        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    MyQueue que;
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    cout << "que.push(2)" << endl;
    cout << "que.push(3)" << endl;
    cout << "que.push(4)" << endl;
    cout << "que.push(5)" << endl;
    cout << "que.peek(): " << que.peek() << endl;
    cout << "que.pop(): " << que.pop() << endl;
    cout << "que.empty(): " << que.empty() << endl;
    cout << "que.pop(): " << que.pop() << endl;

    return 0;
}