#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string restoreString(string s, vector<int> &indices);
int main()
{
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << restoreString(s, indices);
    return 0;
}
string restoreString(string s, vector<int> &indices)
{
    string resString = s;

    for (int i = 0; i < s.length(); i++)
        resString[indices[i]] = s[i];

    return resString;
}