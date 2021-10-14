#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isExist(vector<vector<char>> &borad, string &word);
bool dfs(vector<vector<char>> &board, int y, int x, string &word, int wordCharIndex, vector<vector<bool>> &visted);

int main()
{
    vector<vector<char>> mat = {{'A', 'B', 'C'},
                                {'B', 'Y', 'C'},
                                {'H', 'U', 'D'}};

    string t = "ABCCD";
    cout << isExist(mat, t);
    return 0;
}

bool dfs(vector<vector<char>> &board, int y, int x, string &word, int wordCharIndex, vector<vector<bool>> &visted)
{
    if (wordCharIndex == word.length() - 1)
        return true;

    visted[y][x] = true;

    if (y > 0 &&
        !visted[y - 1][x] &&
        board[y - 1][x] == word[wordCharIndex + 1] &&
        dfs(board, y - 1, x, word, wordCharIndex + 1, visted))
        return true;

    if (x > 0 &&
        !visted[y][x - 1] &&
        board[y][x - 1] == word[wordCharIndex + 1] &&
        dfs(board, y, x - 1, word, wordCharIndex + 1, visted))
        return true;

    if (y < (board.size() - 1) &&
        !visted[y + 1][x] &&
        board[y + 1][x] == word[wordCharIndex + 1] &&
        dfs(board, y + 1, x, word, wordCharIndex + 1, visted))
        return true;

    if (x < (board[0].size() - 1) &&
        !visted[y][x + 1] &&
        board[y][x + 1] == word[wordCharIndex + 1] &&
        dfs(board, y, x + 1, word, wordCharIndex + 1, visted))
        return true;

    visted[y][x] = false;
    return false;
}

bool isExist(vector<vector<char>> &board, string &word)
{
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visted(rows, vector<bool>(cols, false));

    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            if (board[y][x] == word[0] && dfs(board, y, x, word, 0, visted))
                return true;

    return false;
}