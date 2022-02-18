#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> helperStack;

        for (int i = 0; i < num.length(); i++)
        {
            char c = num[i];

            while (k > 0 && !helperStack.empty() && helperStack.top() > c)
            {
                helperStack.pop();
                k--;
            }

            helperStack.push(c);
        }

        // if num is in asscending order
        while (k > 0)
        {
            helperStack.pop();
            k--;
        }

        // store ans with zeroes
        int n = helperStack.size();
        vector<char> resWithZeros(n);

        for (int i = n - 1; i >= 0; i--)
        {
            resWithZeros[i] = helperStack.top();
            helperStack.pop();
        }

        // cut leading zeros

        int j = 0;
        while (j < n && resWithZeros[j] == '0')
        {
            j++;
        }

        if (j >= n)
            return "0";

        // store ans without zeroes
        string ans(n - j, ' ');
        for (int i = 0; i < ans.length(); i++)
        {
            ans[i] = resWithZeros[i + j];
        }

        return ans;
    }
};

int main()
{

    string num = "10";

    Solution sol;

    cout << sol.removeKdigits(num, 1);
    return 0;
}