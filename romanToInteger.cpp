#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s);

int main()
{
    cout << romanToInt("XIX");

    return 0;
}
int romanToInt(string s)
{
    unordered_map<char, int> dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int result = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int pre = dict[s[i - 1]];
        int curr = dict[s[i]];

        if (pre < curr)
            result -= pre;
        else
            result += pre;
    }

    return result += dict[s[s.size() - 1]];
}