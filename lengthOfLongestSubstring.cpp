#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s);
int main()
{
    int l = lengthOfLongestSubstring("abcabcabaadef");
    cout << "Longest Substring Without Repeating Characters: " << l;
    return 0;
}

// optimal
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;
    unordered_map<char, int> mp;
    int i = -1;
    int j = -1;
    int ans = 1;

    int size = s.length();

    while (true)
    {
        bool f1 = false;
        bool f2 = false;

        while (i < size - 1)
        {
            f1 = true;
            i++;
            mp[s[i]]++;

            if (mp[s[i]] == 2)
            {
                break;
            }
            ans = max(ans, i - j);
        }

        while (j < size - 1)
        {
            f2 = true;
            j++;
            mp[s[j]]--;

            if (mp[s[i]] == 1)
            {
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

// O(n^3) brute force
// int lengthOfLongestSubstring(string s)
// {
//     if (s.length() == 0)
//         return 0;
//     int maxLenght = 1;
//     for (int i = 0; i < s.length(); i++)
//     {
//         int j = i + 1;

//         while (j < s.length())
//         {
//             int k = i;

//             while (k < j)
//             {
//                 if (s[j] == s[k])
//                     break;
//                 k++;
//             }

//             if (k == j)
//             {
//                 maxLenght = max(maxLenght, j - i + 1);
//                 j++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }

//     return maxLenght;
// }
