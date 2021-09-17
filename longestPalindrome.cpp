#include <iostream>
using namespace std;

string longestPalindrome(string s);
bool isPalindrome(int, int, string &s);

int main()
{
    // string s = {'a', 'b', 'c', 'c', 'b', 'a', 'a', 'b', 'a'};
    string s = "abb";
    s = longestPalindrome(s);

    int i = 0;
    while (s[i])
    {
        cout << s[i];
        i++;
    }

    return 0;
}
string longestPalindrome(string s)
{
    string resultString = {s[0]};
    int stringLenght = s.length();
    int left = 0, right = stringLenght - 1;
    int templenght = 0;

    while (left < stringLenght)
    {
        while (right > left)
        {
            if (isPalindrome(left, right, s))
            {
                if (resultString.length() < ((right - left) + 1))
                {
                    //copy the string
                    resultString = s.substr(left, ((right - left) + 1));
                }
            }
            right--;
        }
        if (resultString.length() == stringLenght)
            return s;

        left++;
        right = stringLenght - 1;
    }

    return resultString;
}

bool isPalindrome(int lb, int ub, string &s)
{
    bool result = true;
    while (ub > lb)
    {
        if (s[lb] != s[ub])
            return false;

        ub--;
        lb++;
    }
    return result;
}
