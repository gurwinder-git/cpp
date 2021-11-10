#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat);
int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    mat = updateMatrix(mat);

    for (vector<int> v : mat)
    {
        cout << endl;
        for (int item : v)
        {
            cout << item << "  ";
        }
    }

    return 0;
}

// recursion TLE
//  int minDistance(vector<vector<int>> &mat, int y, int x, vector<vector<bool>> visted)
//  {
//      if (x < 0 || x >= mat[0].size() || y >= mat.size() || y < 0 || visted[y][x] == true)
//          return 100000;

//     if (mat[y][x] == 0)
//         return 0;

//     visted[y][x] = true;
//     int val = 1 + min({minDistance(mat, y, x + 1, visted), minDistance(mat, y + 1, x, visted), minDistance(mat, y - 1, x, visted), minDistance(mat, y, x - 1, visted)});

//     visted[y][x] = false;
//     return val;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
// {
//     vector<vector<int>> updatedMat(mat.size(), vector<int>(mat[0].size()));
//     vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));

//     for (int y = 0; y < mat.size(); y++)
//     {
//         for (int x = 0; x < mat[0].size(); x++)
//         {
//             if (mat[y][x] == 0)
//                 updatedMat[y][x] = 0;
//             else
//                 updatedMat[y][x] = minDistance(mat, y, x, visited);
//         }
//     }
//     return updatedMat;
// }

// optimal solution with queue

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> helperQueue;
    vector<vector<int>> result(mat.size(), vector<int>(mat[0].size()));

    for (int y = 0; y < mat.size(); y++)
    {
        for (int x = 0; x < mat[0].size(); x++)
        {
            if (mat[y][x] == 0)
            {
                result[y][x] = 0;
                helperQueue.push(pair<int, int>(y, x));
            }
            else
            {
                result[y][x] = INT_MAX;
            }
        }
    }

    int totalRows = mat.size();
    int totalCols = mat[0].size();
    while (!helperQueue.empty())
    {
        int currRow = helperQueue.front().first;
        int currCol = helperQueue.front().second;

        int dis = result[currRow][currCol] + 1;

        if (currCol + 1 < totalCols && dis < result[currRow][currCol + 1])
        {
            result[currRow][currCol + 1] = dis;
            helperQueue.push(pair<int, int>(currRow, currCol + 1));
        }
        if (currCol - 1 >= 0 && dis < result[currRow][currCol - 1])
        {
            result[currRow][currCol - 1] = dis;
            helperQueue.push(pair<int, int>(currRow, currCol - 1));
        }
        if (currRow + 1 < totalRows && dis < result[currRow + 1][currCol])
        {
            result[currRow + 1][currCol] = dis;
            helperQueue.push(pair<int, int>(currRow + 1, currCol));
        }
        if (currRow - 1 >= 0 && dis < result[currRow - 1][currCol])
        {
            result[currRow - 1][currCol] = dis;
            helperQueue.push(pair<int, int>(currRow - 1, currCol));
        }

        helperQueue.pop();
    }

    return result;
}