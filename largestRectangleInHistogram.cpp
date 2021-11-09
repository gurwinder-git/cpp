#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int largestRecInHistogram(vector<int> &heights);
int main()
{

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle: " << largestRecInHistogram(heights);
    return 0;
}

// brute force
// int largestRecInHistogram(vector<int> &heights)
// {
//     int ans = INT_MIN;

//     for (int i = 0; i < heights.size(); i++)
//     {
//         int rightBoundry = i + 1;
//         int leftBoundry = i - 1;

//         while (leftBoundry >= 0 && heights[leftBoundry] >= heights[i])
//         {
//             leftBoundry--;
//         }

//         while (rightBoundry < heights.size() && heights[rightBoundry] >= heights[i])
//         {
//             rightBoundry++;
//         }

//         ans = max(ans, (rightBoundry - leftBoundry - 1) * heights[i]);
//     }

//     return ans;
// }

// optimized stack solution

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