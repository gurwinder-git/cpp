#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix);
int main()
{

    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    vector<int> res = spiralMatrix(mat);

    for (int num : res)
    {
        cout << num << "  ";
    }

    return 0;
}
vector<int> spiralMatrix(vector<vector<int>> &matrix)
{
    vector<int> res;

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    // cout << "left " << left << endl;
    // cout << "right " << right << endl;
    // cout << "top " << top << endl;
    // cout << "bottom " << bottom << endl;

    int direction = 0;

    while (left <= right && top <= bottom)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            direction = 1;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            direction = 2;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            direction = 3;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            direction = 0;
        }
    }

    return res;
}