#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();

        s = s + s;
        string alter0;
        string alter1;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                alter0.push_back('0');
                alter1.push_back('1');
            }
            else
            {
                alter0.push_back('1');
                alter1.push_back('0');
            }
        }

        int ans0 = 0;
        int ans1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != alter0[i])
            {
                ans0++;
            }
            if (s[i] != alter1[i])
            {
                ans1++;
            }
        }

        int res = min(ans0, ans1);

        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] != alter0[i - 1])
            {
                ans0--;
            }
            if (s[i - 1] != alter1[i - 1])
            {
                ans1--;
            }

            if (s[i + n - 1] != alter0[i + n - 1])
            {
                ans0++;
            }

            if (s[i + n - 1] != alter1[i + n - 1])
            {
                ans1++;
            }

            res = min(res, min(ans0, ans1));
        }
        return res;
    }
};

int main()
{

    string s = "01001001101";
    Solution sol;
    cout << sol.minFlips(s);
    return 0;
}