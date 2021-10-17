#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s);

int main()
{
    cout << isValid("{[][]");
    return 0;
}
bool isValid(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '[' || c == '{' || c == '(')
            stk.push(c);

        else if (stk.empty() ||
                 (stk.top() == '[' && c != ']') ||
                 (stk.top() == '(' && c != ')') ||
                 (stk.top() == '{' && c != '}'))
            return false;
        else
            stk.pop();
    }

    return stk.empty();
}