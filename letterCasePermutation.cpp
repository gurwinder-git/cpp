#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // pick non-pick like problem so time complextity is O(2^totalChars(s))
    void dfs(string &s, int idx, vector<string> &ans)
    {
        if (idx >= s.length())
        {
            ans.push_back(s);

            return;
        }

        if (!isalpha(s[idx]))
        {
            dfs(s, idx + 1, ans);
        }
        else
        {
            dfs(s, idx + 1, ans);

            s[idx] = toupper(s[idx]);
            dfs(s, idx + 1, ans);
            s[idx] = tolower(s[idx]);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;

        for (int i = 0; i < s.length(); i++)
            if (isalpha(s[i]))
                s[i] = (char)tolower(s[i]);

        dfs(s, 0, ans);
        return ans;
    }
};

int main()
{
    string s = "a1b2";
    Solution sol;
    vector<string> ans = sol.letterCasePermutation(s);

    for (string &str : ans)
    {
        cout << str << "  ";
    }

    return 0;
}