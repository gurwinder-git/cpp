#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    void solve(string &digits, int digitPointer, string &container, vector<string> &map, vector<string> &ans)
    {
        if (digitPointer >= digits.length())
        {
            ans.push_back(container);
            return;
        }

        int num = digits[digitPointer] - '0';
        string &mappedString = map.at(num);

        for (int j = 0; j < mappedString.size(); j++)
        {
            container.push_back(mappedString[j]);
            solve(digits, digitPointer + 1, container, map, ans);
            container.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};

        vector<string> ans;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string container;
        solve(digits, 0, container, map, ans);
        return ans;
    }
};

int main()
{
    string digits = "23";

    Solution sol;

    vector<string> res = sol.letterCombinations(digits);

    for (string &s : res)
    {
        cout << s << "  ";
    }

    return 0;
}