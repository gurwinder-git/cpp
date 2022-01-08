#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isZeroInCol = false;
        bool isZeroInRow = false;

        int totalRows = matrix.size();
        int totalCols = matrix[0].size();

        // checking if first col consist any one
        for (int x = 0; x < totalCols; x++)
        {
            if (matrix[0][x] == 0)
            {
                isZeroInCol = true;
                break;
            }
        }

        // checking if first row consist any one
        for (int y = 0; y < totalRows; y++)
        {
            if (matrix[y][0] == 0)
            {
                isZeroInRow = true;
                break;
            }
        }
        ////////////////////////////////////////////
        for (int y = 1; y < totalRows; y++)
        {
            for (int x = 1; x < totalCols; x++)
            {
                if (matrix[y][x] == 0)
                {
                    matrix[0][x] = 0;
                    matrix[y][0] = 0;
                }
            }
        }
        //////////////////////////////////////////

        for (int x = 1; x < totalCols; x++)
        {
            if (matrix[0][x] == 0)
            {
                for (int y = 1; y < totalRows; y++)
                {
                    matrix[y][x] = 0;
                }
            }
        }

        for (int y = 1; y < totalRows; y++)
        {
            if (matrix[y][0] == 0)
            {
                for (int x = 1; x < totalCols; x++)
                {
                    matrix[y][x] = 0;
                }
            }
        }
        ////////////////////////////////////////////////
        if (isZeroInRow)
        {
            for (int y = 0; y < totalRows; y++)
            {
                matrix[y][0] = 0;
            }
        }
        if (isZeroInCol)
        {
            for (int x = 0; x < totalCols; x++)
            {
                matrix[0][x] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};

    Solution sol;

    sol.setZeroes(matrix);

    for (vector<int> v : matrix)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}