#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

private:
    int solve(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int y, int x, int totalTower)
    {

        if (y < 0 || x < 0 || y >= matrix.size() || x >= matrix[0].size())
        {
            return 0;
        }

        if (totalTower == 4)
        {
            return matrix[y][x];
        }
        visited[y][x] = true;

        // top/bottom = y
        // left/right = x

        int top = 0, bottom = 0, left = 0, right = 0, topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;

        if (y - 1 >= 0 && visited[y - 1][x] == false)
            top = solve(matrix, visited, y - 1, x, totalTower + 1);

        if (y + 1 < matrix.size() && visited[y + 1][x] == false)
            bottom = solve(matrix, visited, y + 1, x, totalTower + 1);

        if (x - 1 >= 0 && visited[y][x - 1] == false)
            left = solve(matrix, visited, y, x - 1, totalTower + 1);

        if (x + 1 < matrix[0].size() && visited[y][x + 1] == false)
            right = solve(matrix, visited, y, x + 1, totalTower + 1);

        if (y - 1 >= 0 && x - 1 >= 0 && visited[y - 1][x - 1] == false)
            topLeft = solve(matrix, visited, y - 1, x - 1, totalTower + 1);

        if (y - 1 >= 0 && x + 1 < matrix[0].size() && visited[y - 1][x + 1] == false)
            topRight = solve(matrix, visited, y - 1, x + 1, totalTower + 1);

        if (y + 1 < matrix.size() && x - 1 >= 0 && visited[y + 1][x - 1] == false)
            bottomLeft = solve(matrix, visited, y + 1, x - 1, totalTower + 1);

        if (y + 1 < matrix.size() && x + 1 < matrix[0].size() && visited[y + 1][x + 1] == false)
            bottomRight = solve(matrix, visited, y + 1, x + 1, totalTower + 1);

        visited[y][x] = false;

        return max({top, bottom, left, right, bottomLeft, bottomRight, topLeft, topRight}) + matrix[y][x];
    }

public:
    int maxCoveredPeople(vector<vector<int>> &matrix)
    {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int ans = 0;
        for (int y = 0; y < matrix.size(); y++)
        {
            for (int x = 0; x < matrix[0].size(); x++)
            {
                ans = max(ans, solve(matrix, visited, y, x, 1));
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {150, 450, 100, 320},
        {120, 130, 160, 110},
        {10, 60, 200, 220}};

    Solution sol;

    cout << sol.maxCoveredPeople(matrix) << endl;
    system("PAUSE");

    return 0;
}