#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string str1, string str2)
    {
        stack<char> ss;
        stack<char> st;

        int i = 0, j = 0;

        while (i < str1.size())
        {
            if (str1[i] == '#')
            {
                if (!ss.empty())
                    ss.pop();
            }
            else
            {
                ss.push(str1[i]);
            }
            i++;
        }

        while (j < str2.size())
        {
            if (str2[j] == '#')
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(str2[j]);
            }
            j++;
        }

        while (!ss.empty() && !st.empty())
        {
            if (ss.top() != st.top())
                return false;
            ss.pop();
            st.pop();
        }

        return ss.empty() && st.empty();
    }
};

int main()
{
    string s = "y#fo##f", t = "y#f#o##f";
    Solution sol;
    cout << sol.backspaceCompare(s, t);
    return 0;
}