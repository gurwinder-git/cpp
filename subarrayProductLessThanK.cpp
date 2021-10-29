#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {10, 5, 2, 4, 3, 4, 6};
    cout << numSubarrayProductLessThanK(nums, 100);

    return 0;
}

// brute force
// int numSubarrayProductLessThanK(vector<int> &nums, int k)
// {
//     int totalSubArrays = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int currProduct = 1;
//         for (int j = i; j < nums.size(); j++)
//         {
//             currProduct *= nums[j];
//             if (currProduct < k)
//                 totalSubArrays++;
//             else
//                 break;
//         }
//     }

//     return totalSubArrays;
// }

// using sliding window
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k == 0)
        return 0;

    int totalSubArrays = 0;
    int product = 1;
    int start, end;
    start = end = 0;

    for (end; end < nums.size(); end++)
    {
        product *= nums[end];

        while (product >= k && start < nums.size())
        {
            product /= nums[start];
            start++;
        }

        if (product < k)
            totalSubArrays += end - start + 1;
    }

    return totalSubArrays;
}