#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
bool wordBreak(string s, vector<string> &wordDict);

class Solution
{
public:
    // memo
    unordered_set<string> dict;

    bool solve(string &s, int start, vector<int> &memo)
    {
        if (start >= s.length())
        {
            return true;
        }

        if (memo[start] != -1)
        {
            return memo[start];
        }

        for (int i = start; i < s.length(); i++)
        {
            string subStr = s.substr(start, i - start + 1);

            if (dict.find(subStr) != dict.end())
            {
                if (solve(s, i + 1, memo) == true)
                {
                    return true;
                }
            }
        }

        memo[start] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string &w : wordDict)
            this->dict.insert(w);

        vector<int> memo(s.length(), -1);
        return solve(s, 0, memo);
    }
};

int main()
{
    string s = "catsand";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution sol;

    cout << sol.wordBreak(s, wordDict);

    // cout << wordBreak(s, wordDict);
    return 0;
}

// old
// bool wordBreak(string s, vector<string> &wordDict)
// {
//     vector<bool> dp(s.size() + 1, false);
//     dp[0] = true;

//     for (int i = 0; i < s.size(); i++)
//         for (int j = i + 1; j < dp.size(); j++)
//             if (dp[i] && (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end()))
//                 dp[j] = true;

//     return dp.back();
// }