#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascalTriangle(int numRows);
int main()
{
    vector<vector<int>> res = pascalTriangle(5);
    cout << "[";
    for (vector<int> vec : res)
    {
        cout << "[ ";
        for (int item : vec)
        {
            cout << item << " ";
        }
        cout << "] ";
    }
    cout << "]";
    return 0;
}

vector<vector<int>> pascalTriangle(int numRows)
{
    vector<vector<int>> res;

    vector<int> row;
    row.push_back(1);

    res.push_back(row);

    for (int y = 1; y < numRows; y++)
    {
        res.push_back(vector<int>(y + 1));

        for (int x = 0; x <= y; x++)
        {
            if (x == 0 || x == y)
            {
                res[y][x] = 1;
            }
            else
            {
                res[y][x] = res[y - 1][x - 1] + res[y - 1][x];
            }
        }
    }
    return res;
}