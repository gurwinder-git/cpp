#include <iostream>
#include <algorithm>
using namespace std;

string longestPalindrome(string s);
bool isPalindrome(int, int, string &s);

int main()
{
    // string s = {'a', 'b', 'c', 'c', 'b', 'a', 'a', 'b', 'a'};
    string s = "cbbd";
    s = longestPalindrome(s);
    cout << s;

    return 0;
}

string longestPalindrome(string s)
{
    int len = s.length();
    int start = 0;
    int end = 0;

    for (int i = 0; i < len; i++)
    {
        // for odd lenght
        int left = i, right = i;

        while (left >= 0 && right < len && s[left] == s[right])
        {
            left--;
            right++;
        }

        if (end - start < right - left)
        {
            start = left;
            end = right;
        }

        // for even lenght
        left = i, right = i + 1;

        while (left >= 0 && right < len && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (end - start < right - left)
        {
            start = left;
            end = right;
        }
    }

    start++;
    string res;
    while (start < end)
    {
        res.push_back(s[start]);
        start++;
    }

    return res;
}

// NOT GOOD SOLUTION HARD TO UNDERSTAND my early stage
//  string longestPalindrome(string s)
//  {
//      string resultString = {s[0]};
//      int stringLenght = s.length();
//      int left = 0, right = stringLenght - 1;
//      int templenght = 0;

//     while (left < stringLenght)
//     {
//         while ((right - left) >= resultString.length())
//         {
//             if (isPalindrome(left, right, s))
//                 if (resultString.length() < ((right - left) + 1))
//                     resultString = s.substr(left, ((right - left) + 1));

//             right--;
//         }

//         left++;
//         right = stringLenght - 1;
//     }
//     return resultString;
// }

// bool isPalindrome(int lb, int ub, string &s)
// {
//     bool result = true;
//     while (ub > lb)
//     {
//         if (s[lb] != s[ub])
//             return false;

//         ub--;
//         lb++;
//     }
//     return result;
// }
