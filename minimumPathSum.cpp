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

int dfs(vector<vector<int>> &grid, int y, int x)
{
    if (y == grid.size() - 1 && x == grid.size())
        return grid[y][x];

    if (y >= grid.size() || x >= grid[0].size())
        return INT_MAX;

    return min(dfs(grid, y, x + 1), dfs(grid, y + 1, x)) + grid[y][x];
}

int minCostPathSum(vector<vector<int>> &matrix)
{
    return dfs(matrix, 0, 0);
}