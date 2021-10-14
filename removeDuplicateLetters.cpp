#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string removeDuplicateLetters(string s);
int main()
{

    string s = "abcdeedcba";
    cout << removeDuplicateLetters(s) << '\n';
    return 0;
}

string removeDuplicateLetters(string s)
{
    unordered_set<char> st;
    for (char c : s)
        st.insert(c);

    string res;
    for (int i = 0; i < st.size(); i++)
        cout << *st.begin(i);
    return res;
}