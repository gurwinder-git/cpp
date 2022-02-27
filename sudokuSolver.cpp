#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0);
    }

    bool isValid(vector<vector<char>> &board, char c, int subY, int subX, int y, int x)
    {
        // check for row and col;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][x] == c || board[y][i] == c)
                return false;
        }

        // check for sub matrix
        for (int y = subY; y < subY + 3; y++)
            for (int x = subX; x < subX + 3; x++)
                if (board[y][x] == c)
                    return false;

        return true;
    }

    bool solve(vector<vector<char>> &board, int y)
    {
        // find empty block
        int x;
        bool found = false;

        for (y; y < 9; y++)
        {
            for (x = 0; x < 9; x++)
            {
                if (board[y][x] == '.')
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        if (y >= 9 && x >= 9)
            return true;

        int subY = (y / 3) * 3;
        int subX = (x / 3) * 3;

        for (char c = '1'; c <= '9'; c++)
        {
            if (isValid(board, c, subY, subX, y, x))
            {
                board[y][x] = c;

                if (solve(board, y) == true)
                    return true;
                else
                    board[y][x] = '.';
            }
        }

        return false;
    }
};
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    sol.solveSudoku(board);

    for (vector<char> &line : board)
    {
        for (char c : line)
            cout << c << "  ";
        cout << endl;
    }
    return 0;
}