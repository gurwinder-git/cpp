#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s);
int main()
{
    cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring("abcabcaabb");
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    vector<char> charStack;
    int length = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (!(count(charStack.begin(), charStack.end(), s[i])))
        {
            charStack.push_back(s[i]);
        }
        else
        {
            if (length < charStack.size())
            {
                length = charStack.size();
            }
            charStack.clear();
            charStack.push_back(s[i]);
        }
    }

    if (length < charStack.size())
    {
        length = charStack.size();
    }

    return length;
}