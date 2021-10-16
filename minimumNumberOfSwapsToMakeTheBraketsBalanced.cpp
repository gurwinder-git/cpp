#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int minSwaps(string s);

int main()
{
    cout << minSwaps("[]][[[]]");

    return 0;
}

// int minSwaps(string s)
// {
//     int maxClose = 0, close = 0;

//     for (char c : s)
//     {
//         close = c == ']' ? close + 1 : close - 1;
//         maxClose = max(maxClose, close);
//     }
//     return (maxClose + 1) / 2;
// }

// using stack
int minSwaps(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '[')
            stk.push(c);
        if (c == ']' && stk.size() != 0)
            stk.pop();
    }

    return (stk.size() + 1) / 2;
}