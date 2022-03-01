#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums);
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}
// brutte force TLE
// int maxSubArray(vector<int> &nums)
// {
//     int maxSum = nums[0];

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < nums.size(); j++)
//         {
//             sum += nums[j];
//             if (sum > maxSum)
//             {
//                 maxSum = sum;
//             }
//         }
//     }
//     return maxSum;
// }

int maxSubArray(vector<int> &nums)
{
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (currentSum >= 0) // then join that subArray
        {
            currentSum += nums[i];
        }
        else
        {
            currentSum = nums[i];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}