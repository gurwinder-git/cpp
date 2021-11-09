#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> previousSmaller(vector<int> &nums);
int main()
{
    vector<int> nums = {4, 10, 5, 8, 20, 15, 3, 12};
    nums = previousSmaller(nums);

    for (int num : nums)
        cout << num << "  ";

    return 0;
}

// brute force
// vector<int> previousSmaller(vector<int> &nums)
// {
//     vector<int> ans(nums.size());

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int j = i - 1;
//         for (; j >= 0; j--)
//         {
//             if (nums[j] < nums[i])
//             {
//                 break;
//             }
//         }

//         if (j < 0)
//             ans[i] = -1;
//         else
//             ans[i] = nums[j];
//     }

//     return ans;
// }

// using stack optimized O(n) time and O(n) space complexity

vector<int> previousSmaller(vector<int> &nums)
{
    stack<int> helperStack;
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        while (!helperStack.empty() && nums[helperStack.top()] > nums[i])
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
