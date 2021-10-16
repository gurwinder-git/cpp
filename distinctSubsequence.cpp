#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int distinctSubsequences(string s);

int main()
{
    cout << distinctSubsequences("abcdab");
    return 0;
}
int distinctSubsequences(string s)
{
    int mod = 1e9 + 7;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    cout << dp.size() << endl;

    map<char, int> helperMap;

    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        cout << dp[i] << endl;
        char c = s[i - 1];
        if (helperMap[c] > 0)
        {
            int j = helperMap[c];
            dp[i] = (dp[i] - dp[j - 1]) % mod;
        }

        helperMap[c] = i;
    }
    if (dp[n] < 0)
        dp[n] += mod;
    return dp[n] - 1;
}
