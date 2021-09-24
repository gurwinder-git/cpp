#include <iostream>
#include <string>

using namespace std;

void reverseString(string &s);
int main()
{

    string s = "Gurwinder Singh";
    reverseString(s);
    cout << s;
    return 0;
}
void reverseString(string &s)
{
    int lb = 0;
    int ub = s.length() - 1;

    while (lb < ub)
    {
        swap(s[lb], s[ub]);
        lb++;
        ub--;
    }
}