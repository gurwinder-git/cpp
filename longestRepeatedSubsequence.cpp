#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestRepeatedSubsequence(string s1);
int main()
{
    string s1 = "aab";
    cout << longestRepeatedSubsequence(s1);
    return 0;
}

int LRS(string s1, string s2)
{
    vector<vector<int>> matrix(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for (int y = 1; y <= s1.size(); y++)
        for (int x = 1; x <= s2.size(); x++)
            if (s1[y - 1] == s2[x - 1] && (y - 1 != x - 1))
                matrix[y][x] = matrix[y - 1][x - 1] + 1;
            else
                matrix[y][x] = max(matrix[y - 1][x], matrix[y][x - 1]);

    return matrix[s1.size()][s2.size()];
}

int longestRepeatedSubsequence(string s1)
{
    return LRS(s1, s1);
}
