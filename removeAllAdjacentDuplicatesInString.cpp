#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string removeDuplicates(string s);

int main()
{
    string s = "abbacs";
    cout << removeDuplicates(s);
    return 0;
}
string removeDuplicates(string s)
{
    string res;
    for (char c : s)
    {
        if (res.empty() || c != res.back())
            res.push_back(c);
        else
            res.pop_back();
    }
    return res;
}