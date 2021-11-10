#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int largestRectangle(vector<vector<char>> &matrix);
int main()
{

    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    cout << "Largest rectangle: " << largestRectangle(matrix);
    return 0;
}

vector<int> nextSmaller(vector<int> &nums)
{
    stack<int> helperStack;
    vector<int> res(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!helperStack.empty() && nums[helperStack.top()] >= nums[i])
        {
            helperStack.pop();
        }

        if (helperStack.empty())
            res[i] = nums.size();
        else
            res[i] = helperStack.top();

        helperStack.push(i);
    }

    return res;
}

vector<int> previousSmaller(vector<int> &nums)
{
    stack<int> helperStack;
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        while (!helperStack.empty() && nums[helperStack.top()] >= nums[i])
        {
            helperStack.pop();
        }

        if (helperStack.empty())
            res[i] = -1;
        else
            res[i] = helperStack.top();

        helperStack.push(i);
    }

    return res;
}

int largestRecInHistogram(vector<int> &heights)
{
    int ans = INT_MIN;

    vector<int> preSmallerBoundres = previousSmaller(heights);
    vector<int> nextSmallerBoundres = nextSmaller(heights);

    for (int i = 0; i < heights.size(); i++)
        ans = max(ans, (nextSmallerBoundres[i] - preSmallerBoundres[i] - 1) * heights[i]);

    return ans;
}

int largestRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    int result = INT_MIN;

    vector<int> currentRow(matrix[0].size(), 0);

    for (int y = 0; y < matrix.size(); y++)
    {
        for (int x = 0; x < matrix[0].size(); x++)
        {
            if (matrix[y][x] == '1')
                currentRow[x] += 1;
            else
                currentRow[x] = 0;
        }

        result = max(result, largestRecInHistogram(currentRow));
    }

    return result;
}