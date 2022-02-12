#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int j = s.length() - 1;

        while(j >= 0 && s[j] == ' ')
            j--;

        int i = j;

        while (i >= 0 && s[i] != ' ')
            i--;

        return (j - i);
    }
};

int main()
{
    Solution sol;
    cout<<sol.lengthOfLastWord("     fly me   to   the moon  ");
    return 0;
}