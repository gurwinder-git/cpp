#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int totalIslands(vector<vector<int>> &grid);
int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    cout << totalIslands(mat);
    return 0;
}

void markVisited(vector<vector<int>> &grid, int y, int x, vector<vector<bool>> &visted)
{
    visted[y][x] = true;

    if (x + 1 < grid[0].size() && grid[y][x + 1] == 1 && visted[y][x + 1] == false)
        markVisited(grid, y, x + 1, visted);

    if (x - 1 >= 0 && grid[y][x - 1] == 1 && visted[y][x - 1] == false)
        markVisited(grid, y, x - 1, visted);

    if (y + 1 < grid.size() && grid[y + 1][x] == 1 && visted[y + 1][x] == false)
        markVisited(grid, y + 1, x, visted);

    if (y - 1 >= 0 && grid[y - 1][x] == 1 && visted[y - 1][x] == false)
        markVisited(grid, y - 1, x, visted);
}

int totalIslands(vector<vector<int>> &grid)
{
    int totalIslands = 0;

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    for (int y = 0; y < grid.size(); y++)
    {
        for (int x = 0; x < grid[0].size(); x++)
        {
            if (grid[y][x] == 1 && visited[y][x] == false)
            {
                totalIslands++;
                markVisited(grid, y, x, visited);
            }
        }
    }

    return totalIslands;
}