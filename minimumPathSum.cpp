#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCostPathSum(vector<vector<int>> &matrix);
int main()
{
    vector<vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int num = minCostPathSum(matrix);
    cout << num;
    return 0;
}

// using memorization

// int dfs(vector<vector<int>> &grid, int y, int x, vector<vector<int>> &dp)
// {
//     if (y == grid.size() - 1 && x == grid.size())
//         return grid[y][x];

//     if (y >= grid.size() || x >= grid[0].size())
//         return INT_MAX;

//     if (dp[y][x] != -1)
//         return dp[y][x];

//     dp[y][x] = min(dfs(grid, y, x + 1, dp), dfs(grid, y + 1, x, dp)) + grid[y][x];
//     return dp[y][x];
// }

// int minCostPathSum(vector<vector<int>> &matrix)
// {
//     vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
//     return dfs(matrix, 0, 0, dp);
// }

// using dp

int minCostPathSum(vector<vector<int>> &grid)
{
    int rows = grid.size() - 1;
    int cols = grid[0].size() - 1;

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
    dp[rows][cols] = grid[rows][cols];

    for (int x = cols - 1; x >= 0; x--)
        dp[rows][x] = dp[rows][x + 1] + grid[rows][x];

    for (int y = rows - 1; y >= 0; y--)
        for (int x = cols; x >= 0; x--)
        {
            if (x == cols)
                dp[y][x] = dp[y + 1][x] + grid[y][x];
            else
                dp[y][x] = min(dp[y + 1][x], dp[y][x + 1]) + grid[y][x];
        }

    return dp[0][0];
}