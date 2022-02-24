#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> res;

    void solve(string &pattren, int opened, int closed, int &n)
    {
        if (pattren.size() == n * 2)
        {
            res.push_back(pattren);
            return;
        }

        if (opened < n)
        {
            pattren.push_back('(');
            solve(pattren, opened + 1, closed, n);
            pattren.pop_back();
        }

        if (opened > closed)
        {
            pattren.push_back(')');
            solve(pattren, opened, closed + 1, n);
            pattren.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string pattren;
        solve(pattren, 0, 0, n);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);

    for (string s : res)
        cout << s << "  ";
    return 0;
}
