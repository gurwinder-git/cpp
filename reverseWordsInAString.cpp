#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // O(2n) time O(n) space
    string reverseWords(string s)
    {
        string res;
        int n = s.length();
        int start = n - 1;
        int end = start;

        while (start >= 0)
        {
            while (start >= 0 && s[start] == ' ')
            {
                start--;
            }

            end = start;

            while (start >= 0 && s[start] != ' ')
            {
                start--;
            }

            // push result
            if (s[start + 1] != ' ')
            {
                int i = start + 1;
                int j = end;

                while (i <= j)
                {
                    res.push_back(s[i]);
                    i++;
                }
                res.push_back(' ');
            }
        }

        res.pop_back();
        return res;
    }
};

int main()
{

    string s = "a good   example   ";
    Solution sol;

    cout << sol.reverseWords(s);
    return 0;
}