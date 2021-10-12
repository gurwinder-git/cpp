#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix);
int main()
{

    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    rotateMatrix(mat);

    for (vector<int> vec : mat)
    {
        for (int num : vec)
        {
            cout << num << "  ";
        }
        cout << endl;
    }

    return 0;
}

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int y = 0; y < n; y++)
        for (int x = y; x < n; x++)
            swap(matrix[y][x], matrix[x][y]);

    for (int y = 0; y < n; y++)
    {
        int l = 0;
        int u = n - 1;
        while (l < u)
        {
            swap(matrix[y][l], matrix[y][u]);
            l++;
            u--;
        }
    }
}