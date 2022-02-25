#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> res;
    bool isValidPart(string &s, int start, int len)
    {
        if (start + len > s.length())
            return false;

        string subPart = s.substr(start, len);
        if (subPart.length() > 1 && subPart[0] == '0')
            return false;

        if (stoi(subPart) > 255)
            return false;

        return true;
    }
    void solve(string &s, int start, string curr, int part)
    {
        if (start == s.length() && part == 4)
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }

        if (isValidPart(s, start, 1))
            solve(s, start + 1, curr + s.at(start) + '.', part + 1);

        if (isValidPart(s, start, 2))
            solve(s, start + 2, curr + s.substr(start, 2) + '.', part + 1);

        if (isValidPart(s, start, 3))
            solve(s, start + 3, curr + s.substr(start, 3) + '.', part + 1);
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() > 12)
            return res;

        solve(s, 0, "", 0);
        return res;
    }
};

int main()
{
    string ip = "25525511135";
    Solution sol;

    vector<string> res = sol.restoreIpAddresses(ip);
    for (string &s : res)
        cout << s << "  ";

    return 0;
}