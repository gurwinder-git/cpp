#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> partion(string s);
int main()
{

    string s = "abbaba";

    vector<vector<string>> res = partion(s);
    for (vector<string> v : res)
    {
        cout << "[";
        for (string s : v)
        {
            cout << s << " ";
        }

        cout << "]";
    }

    return 0;
}
bool palindrom(string &s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}
void solve(string &s, vector<vector<string>> &res, vector<string> &vec)
{
    if (s.length() == 0)
    {
        res.push_back(vec);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        string prefix = s.substr(0, i + 1);
        string left = s.substr(i + 1);

        if (palindrom(prefix))
        {
            vec.push_back(prefix);
            solve(left, res, vec);
            vec.pop_back();
        }
    }
}

vector<vector<string>> partion(string s)
{
    vector<vector<string>> res;
    vector<string> vec;
    solve(s, res, vec);
    return res;
}