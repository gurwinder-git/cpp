#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0;
        int i = 0, n = s.length();
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            return 0;

        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        for (; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int digit = s[i] - 48;
                if (ans > (INT_MAX - digit) / 10)
                {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans = (ans * 10) + digit;
            }
            else
                break;
        }

        return ans * sign;
    }
};

int main()
{

    int v = '3' - 48; // 3

    string s = "    -12123   34";
    // string s = "-+12";
    Solution sol;

    cout << sol.myAtoi(s);
    // int p = '-';

    // cout << p;
    return 0;
}