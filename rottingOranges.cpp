#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        queue<pair<int, int>> q;

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        for (int y = 0; y < grid.size(); y++)
            for (int x = 0; x < grid[0].size(); x++)
                if (grid[y][x] == 2)
                    q.push({y, x});

        while (!q.empty())
        {
            int sizeOfQueue = q.size();

            while (sizeOfQueue--)
            {
                pair<int, int> dimention = q.front();
                q.pop();
                int y = dimention.first;
                int x = dimention.second;
                int left = x - 1, right = x + 1, top = y - 1, bottom = y + 1;

                if (left >= 0 && grid[y][left] == 1)
                {
                    grid[y][left] = 2;
                    q.push({y, left});
                }
                if (right < totalCols && grid[y][right] == 1)
                {
                    grid[y][right] = 2;
                    q.push({y, right});
                }
                if (top >= 0 && grid[top][x] == 1)
                {
                    grid[top][x] = 2;
                    q.push({top, x});
                }
                if (bottom < totalRows && grid[bottom][x] == 1)
                {
                    grid[bottom][x] = 2;
                    q.push({bottom, x});
                }
            }

            if (q.size() > 0)
                ans++;
        }

        for (int y = 0; y < grid.size(); y++)
            for (int x = 0; x < grid[0].size(); x++)
                if (grid[y][x] == 1)
                    return -1;

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution sol;
    cout << sol.orangesRotting(grid);
    return 0;
}