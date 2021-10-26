#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix);
int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix);
    return 0;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<short int>> dp(rows, vector<short int>(cols));

    short int size = 0;

    for (int y = rows - 1; y >= 0; y--)
    {
        for (int x = cols - 1; x >= 0; x--)
        {
            if (matrix[y][x] == '0')
                dp[y][x] = 0;
            else
            {
                dp[y][x] = 1;
                size = 1;
            }
        }
    }

    for (int y = rows - 2; y >= 0; y--)
        for (int x = cols - 2; x >= 0; x--)
        {
            {
                if (dp[y][x] != 0)
                    dp[y][x] = min({dp[y][x + 1], dp[y + 1][x], dp[y + 1][x + 1]}) + 1;
                size = max(dp[y][x], size);
            }
        }

    return size * size;
}