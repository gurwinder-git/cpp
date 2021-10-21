#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int getMaximumGold(vector<vector<int>> &grid);

int main()
{
    vector<vector<int>> grid = {{0, 6, 0, 5}, {8, 7, 1, 9}, {0, 1, 0, 0}, {1, 1, 1, 100}};
    cout << getMaximumGold(grid);
    return 0;
}

int dfs(vector<vector<int>> &grid, int y, int x, int n, int m, vector<vector<bool>> &visited)
{
    //  Every time you are located in a cell you will collect all the gold in that cell.
    //  You can't visit the same cell more than once.
    //  Never visit a cell with 0 gold.

    if (y < 0 || y >= n || x < 0 || x >= m || visited[y][x] == true || grid[y][x] == 0)
        return 0;

    visited[y][x] = true;
    int left = dfs(grid, y, x - 1, n, m, visited);
    int right = dfs(grid, y, x + 1, n, m, visited);
    int up = dfs(grid, y - 1, x, n, m, visited);
    int down = dfs(grid, y + 1, x, n, m, visited);
    visited[y][x] = false;

    return max({left, right, up, down}) + grid[y][x];
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int maxGold = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (grid[y][x] != 0)
                maxGold = max(maxGold, dfs(grid, y, x, n, m, visited));

    return maxGold;
}