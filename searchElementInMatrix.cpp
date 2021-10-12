#include <iostream>
#include <vector>
using namespace std;

bool searchTarget(vector<vector<int>> &matrix, int target);
int main()
{

    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    cout << searchTarget(mat, 6);

    return 0;
}

bool searchTarget(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = matrix[0].size();

    int start = 0;
    int end = m * n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int val = matrix[mid / n][mid % n];

        if (val == target)
            return true;

        else if (target > val)
            start = mid + 1;

        else
            end = mid - 1;
    }

    return false;
}