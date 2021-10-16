#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string s1, string s2);
int main()
{
    string s1 = "abckjvsnvkjnkjdbkjsnkjkjlkdvmpemvpremrpbnkjfd";
    string s2 = "poeorjbmlkerlvmlmlvmlmelkrmklvmlkerklmvlk";
    cout << longestCommonSubsequence(s2, s2);
    return 0;
}

// using recursion

// int lcs(string &s1, int i, string &s2, int j)
// {
//     if (s1[i] == '\0' || s2[j] == '\0')
//         return 0;
//     else if (s1[i] == s2[j])
//         return 1 + lcs(s1, i + 1, s2, j + 1);
//     else
//         return max(lcs(s1, i + 1, s2, j), lcs(s1, i, s2, j + 1));
// }

// int longestCommonSubsequence(string s1, string s2)
// {
//     return lcs(s1, 0, s2, 0);
// }

// using dynamic programming

int longestCommonSubsequence(string s1, string s2)
{
    if (s1.size() < s2.size())
        return longestCommonSubsequence(s2, s1);

    vector<vector<int>> matrix(s1.size() + 1, vector<int>(s1.size() + 1));

    for (int y = 1; y <= s1.size(); y++)
        for (int x = 1; x <= s2.size(); x++)
            if (s1[y - 1] == s2[x - 1])
                matrix[y][x] = matrix[y - 1][x - 1] + 1;
            else
                matrix[y][x] = max(matrix[y - 1][x], matrix[y][x - 1]);

    return matrix[s1.size()][s2.size()];
}
