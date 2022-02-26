#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    unordered_set<string> dict;
    vector<string> res;

    void solve(string &s, int i, string sentence)
    {
        if (i == s.length())
        {
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }

        int wordLen = 1;

        for (; i + wordLen <= s.length(); wordLen++)
        {
            if (dict.find(s.substr(i, wordLen)) != dict.end())
            {
                solve(s, i + wordLen, sentence + s.substr(i, wordLen) + " ");
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &s : wordDict)
            this->dict.insert(s);
        solve(s, 0, "");
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = sol.wordBreak("catsanddog", wordDict);

    for (string &s : res)
        cout << s << ", ";
    return 0;
}