#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmaller(vector<int> &nums);
int main()
{
    vector<int> nums = {4, 10, 5, 8, 20, 15, 3, 12};
    nums = nextSmaller(nums);

    for (int num : nums)
        cout << num << "  ";

    return 0;
}

// brute force
// vector<int> nextSmaller(vector<int> &nums)
// {
//     vector<int> ans(nums.size());

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int j = i + 1;
//         for (; j < nums.size(); j++)
//         {
//             if (nums[j] < nums[i])
//             {
//                 break;
//             }
//         }

//         if (j < nums.size())
//             ans[i] = nums[j];
//         else
//             ans[i] = -1;
//     }

//     return ans;
// }

// using stack
vector<int> nextSmaller(vector<int> &nums)
{
    stack<int> helperStack;
    vector<int> res(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!helperStack.empty() && nums[helperStack.top()] > nums[i])
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