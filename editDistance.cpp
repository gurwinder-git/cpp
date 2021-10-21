#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int editDistance(string word1, string word2);

int main()
{
    cout << editDistance("abcd", "abc");
    return 0;
}

int dfs(string &word1, string &word2, int i, int j, vector<vector<short int>> &dp)
{
    if (i >= word1.length())
        return word2.length() - j;

    if (j >= word2.length())
        return word1.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (word1[i] == word2[j])
        return dfs(word1, word2, i + 1, j + 1, dp);
    else
    {
        dp[i][j] = 1 + min(dfs(word1, word2, i, j + 1, dp), min(dfs(word1, word2, i + 1, j, dp), dfs(word1, word2, i + 1, j + 1, dp)));
        return dp[i][j];
    }
}
int editDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    vector<vector<short int>> dp(m, vector<short int>(n, -1));

    return dfs(word1, word2, 0, 0, dp);
}