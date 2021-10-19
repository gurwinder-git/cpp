#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string LP(string s);

int main()
{
    string s = "abbaca";
    cout << LP(s);
    return 0;
}
string LP(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
    string res;

    for (int g = 0; g < s.length(); g++)
    {
        for (int y = 0, x = g; x < s.length(); x++, y++)
        {
            if (g == 0)
                dp[y][x] = true;

            else if (g == 1)
            {
                if (s[y] == s[x])
                    dp[y][x] = true;
                else
                    dp[y][x] = false;
            }
            else
            {
                if (s[y] == s[x] && dp[y + 1][x - 1])
                    dp[y][x] = true;
                else
                    dp[y][x] = false;
            }

            if (dp[y][x])
                res = s.substr(y, x - y + 1);
        }
    }

    return res;
}