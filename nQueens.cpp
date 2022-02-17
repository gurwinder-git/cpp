#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool validLocation(vector<string> &board, int n, int row, int col)
    {

        // check left diagonal upper
        int y = row - 1;
        int x = col - 1;

        while (y >= 0 && x >= 0)
        {
            if (board[y][x] == 'Q')
                return false;

            y--;
            x--;
        }

        // chech right diagonal
        y = row - 1;
        x = col + 1;

        while (y >= 0 && x < n)
        {
            if (board[y][x] == 'Q')
                return false;

            y--;
            x++;
        }

        // check up because we filling from up to down

        y = row - 1;
        x = col;

        while (y >= 0)
        {
            if (board[y][x] == 'Q')
                return false;
            y--;
        }

        return true;
    }

    void solve(vector<string> &board, int row, int n, vector<vector<string>> &ans)
    {
        if (row >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (validLocation(board, n, row, col))
            {
                board[row][col] = 'Q';
                solve(board, row + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n, ans);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(4);

    for (vector<string> grid : res)
    {
        for (string row : grid)
        {
            cout << row << endl;
        }
        cout << "**********" << endl;
    }

    return 0;
}