#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string &s, string &t);
int main()
{
    string s = "badc";
    string t = "baba";
    cout << (isIsomorphic(s, t) ? "true" : "false");
    return 0;
}

bool isIsomorphic(string &s, string &t)
{
    unordered_map<char, char> helperMap;

    int i = s.length();
    while (i--)
    {
        if (!helperMap[s[i]])
            helperMap[s[i]] = t[i];
        else
        {
            if (helperMap[s[i]] != t[i])
                return false;
        }
    }

    helperMap.clear();
    i = t.length();
    while (i--)
    {
        if (!helperMap[t[i]])
            helperMap[t[i]] = s[i];
        else
        {
            if (helperMap[t[i]] != s[i])
                return false;
        }
    }

    return true;
}