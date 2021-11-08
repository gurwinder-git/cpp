#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle);
int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "minimum Total: " << minimumTotal(triangle);
    return 0;
}

// using recursion brute force

// int dfs(vector<vector<int>> &triangle, int y, int x)
// {
//     if (y >= triangle.size())
//         return 0;

//     int minNum = INT_MAX;

//     minNum = min(triangle[y][x] + dfs(triangle, y + 1, x), triangle[y][x] + dfs(triangle, y + 1, x + 1));

//     return minNum;
// }

// int minimumTotal(vector<vector<int>> &triangle)
// {
//     return dfs(triangle, 0, 0);
// }

// using dp
int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();
    vector<int> dp(rows);

    for (int i = 0; i < rows; i++)
        dp[i] = triangle[rows - 1][i];

    for (int y = rows - 2; y >= 0; y--)
    {
        for (int x = 0; x < triangle[y].size(); x++)
        {
            dp[x] = min(dp[x], dp[x + 1]) + triangle[y][x];
        }
    }

    return dp[0];
}