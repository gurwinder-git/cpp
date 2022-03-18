#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // memo
    int solve(string &s, int start, vector<int> &memo)
    {
        if (start == s.length())
        {
            return 1;
        }

        if (s[start] == '0')
        {
            return 0;
        }

        if (start == s.length() - 1)
        {
            return 1;
        }

        if (memo[start] != 0)
        {
            return memo[start];
        }

        int way1 = solve(s, start + 1, memo);

        int way2 = 0;
        string subStr = s.substr(start, 2);
        if (stoi(subStr) >= 0 && stoi(subStr) <= 26)
        {
            way2 = solve(s, start + 2, memo);
        }

        return memo[start] = way1 + way2;
    }

    int numDecodings(string s)
    {
        vector<int> memo(s.length());
        return solve(s, 0, memo);
    }

    // my first brute force
    // private:
    //     int ans;

    //     void solve(string &s, int start)
    //     {
    //         if (start >= s.length())
    //         {
    //             ans++;
    //             return;
    //         }

    //         if (s[start] == '0')
    //         {
    //             return;
    //         }

    //         for (int i = start; i < start + 2 && i < s.length(); i++)
    //         {
    //             string subStr = s.substr(start, i - start + 1);
    //             int num = stoi(subStr);
    //             if (num >= 1 && num <= 26)
    //             {
    //                 solve(s, i + 1);
    //             }
    //         }
    //     }

    // public:
    //     int numDecodings(string s)
    //     {
    //         ans = 0;
    //         solve(s, 0);
    //         return ans;
    //     }
};

int main()
{
    string s = "226";
    Solution sol;

    cout << sol.numDecodings(s);
    return 0;
}