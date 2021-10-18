#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool wordBreak(string s, vector<string> &wordDict);

int main()
{
    string s = "catsand";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    cout << wordBreak(s, wordDict);
    return 0;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < dp.size(); j++)
            if (dp[i] && (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end()))
                dp[j] = true;

    return dp.back();
}