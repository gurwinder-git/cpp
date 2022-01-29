#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        bool notMatched = false;

        // min size of string
        int minStrLen = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
        {
            if (minStrLen > strs[i].length())
                minStrLen = strs[i].length();
        }

        string res;

        for (int x = 0; x < minStrLen; x++)
        {
            for (int y = 1; y < strs.size(); y++)
            {
                if (strs[y][x] != strs[0][x])
                {
                    notMatched = true;
                    break;
                }
            }

            if (notMatched)
                break;
            else
                res.push_back(strs[0][x]);
        }

        return res;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    Solution sol;

    cout << sol.longestCommonPrefix(strs);
    return 0;
}