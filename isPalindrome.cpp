#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &s);
int main()
{

    string s = "abcdeedcba";
    cout << isPalindrome(s) << '\n';
    cout << ('a' < 'b');
    return 0;
}
bool isPalindrome(string &s)
{
    int lb = 0;
    int ub = s.length() - 1;

    while (lb < ub)
    {
        if (!isalnum(s[lb]))
            lb++;
        else if (!isalnum(s[ub]))
            ub--;
        else if (tolower(s[lb]) != tolower(s[ub]))
            return false;
        else
        {
            lb++;
            ub--;
        }
    }

    return true;
}