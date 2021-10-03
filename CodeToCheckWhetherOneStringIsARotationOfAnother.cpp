#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

bool rotateString(string &s, string &goal);
int main()
{
    string s = "string";
    string goal = "trings";
    cout << rotateString(s, goal);
    return 0;
}
bool rotateString(string &s, string &goal)
{
    if (s.length() != goal.length())
        return false;

    queue<char> qS, qGoal;

    for (int i = 0; i < s.length(); i++)
    {
        qS.push(s[i]);
        qGoal.push(goal[i]);
    }

    int i = s.length();

    while (i--)
    {
        if (qS == qGoal)
            return true;

        qS.push(qS.front());
        qS.pop();
    }

    return false;
}