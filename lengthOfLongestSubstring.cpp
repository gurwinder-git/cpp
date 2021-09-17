#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int lengthOfLongestSubstring(string s);
int findIndex(vector<char> &vec, char c);
int main()
{
    int l = lengthOfLongestSubstring("abcabcabaadef");
    cout << "Longest Substring Without Repeating Characters: " << l;
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    vector<char> distinctString;
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++)
    {
        //if char not exit in vector
        if (count(distinctString.begin(), distinctString.end(), s[i]) == 0)
        {
            distinctString.push_back(s[i]);
        }
        //if char exit in vector
        else
        {
            if (distinctString.size() > maxLength)
                maxLength = distinctString.size();

            //then find the index of that chacracter
            int index = findIndex(distinctString, s[i]);
            distinctString.erase(distinctString.begin(), distinctString.begin() + (index + 1));
            distinctString.push_back(s[i]);
        }
    }
    if (distinctString.size() > maxLength)
        maxLength = distinctString.size();

    return maxLength;
}

int findIndex(vector<char> &vec, char c)
{
    std::vector<char>::iterator itr = std::find(vec.begin(), vec.end(), c);
    return std::distance(vec.begin(), itr);
}