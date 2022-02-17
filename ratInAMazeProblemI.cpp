#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> res;
    string path;

    void dfs(vector<vector<int>> &matrix, int y, int x, int n, vector<vector<bool>> &visited)
    {
        if (x == n - 1 && y == n - 1)
        {
            res.push_back(path);
            return;
        }
        visited[y][x] = true;

        // go left
        if (x - 1 >= 0 && visited[y][x - 1] != true && matrix[y][x - 1] != 0)
        {
            path.push_back('L');
            dfs(matrix, y, x - 1, n, visited);
            path.pop_back();
        }

        // go right
        if (x + 1 < n && visited[y][x + 1] != true && matrix[y][x + 1] != 0)
        {
            path.push_back('R');
            dfs(matrix, y, x + 1, n, visited);
            path.pop_back();
        }

        // go up
        if (y - 1 >= 0 && visited[y - 1][x] != true && matrix[y - 1][x] != 0)
        {
            path.push_back('U');
            dfs(matrix, y - 1, x, n, visited);
            path.pop_back();
        }

        // go down
        if (y + 1 < n && visited[y + 1][x] != true && matrix[y + 1][x] != 0)
        {
            path.push_back('D');
            dfs(matrix, y + 1, x, n, visited);
            path.pop_back();
        }

        visited[y][x] = false;
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n)
    {
        if (matrix[0][0] == 0 || matrix[n - 1][n - 1] == 0)
            return res;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        dfs(matrix, 0, 0, n, visited);

        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 0, 1},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 1}};

    Solution sol;

    vector<string> res = sol.findPath(matrix, 4);

    for (string s : res)
    {
        cout << s << "  ";
    }
    return 0;
}
