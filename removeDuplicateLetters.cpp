#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeDuplicateLetters(string s);
int main()
{

    string s = "abcdeedcba";
    cout << removeDuplicateLetters(s) << '\n';
    return 0;
}

// void getIndex(vector<int> v, int K)
// {
//     auto it = find(v.begin(), v.end(), K);

//     // If element was found
//     if (it != v.end())
//     {
//         int index = it - v.begin();
//         cout << index << endl;
//     }
// }

string removeDuplicateLetters(string s)
{
    string res;
    string::iterator it = s.begin();
    while (it != s.end())
    {
        string::iterator indexOfCharIfExit = find(res.begin(), res.end(), *it);
        //if not found
        if (indexOfCharIfExit == res.end())
        {
            res.push_back(*it);
        }
        //if found
        else
        {
            int index = indexOfCharIfExit - res.begin();
        }

        it++;
    }

    return res;
}