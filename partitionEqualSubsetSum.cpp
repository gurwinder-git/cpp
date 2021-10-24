#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int> &nums);

int main()
{

    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
    // system("pause>0");
    return 0;
}

// using recursion

// bool usingRecursion(vector<int> &nums, int n, int sum)
// {
//     if (sum <= 0)
//         return sum == 0;

//     if (n < 0)
//         return false;

//     return usingRecursion(nums, n - 1, sum - nums[n - 1]) || usingRecursion(nums, n - 1, sum);
// }

// bool canPartition(vector<int> &nums)
// {
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//         sum += nums[i];

//     if (sum % 2 != 0)
//         return false;

//     return usingRecursion(nums, nums.size(), sum / 2);
// }

// using  dp TLE
// bool canPartition(vector<int> &nums)
// {
//     int target = 0;

//     for (int i = 0; i < nums.size(); i++)
//         target += nums[i];

//     if (target % 2 != 0)
//         return false;

//     target /= 2;

//     vector<int> dp;
//     dp.push_back(0);

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int dpSize = dp.size();

//         for (int j = 0; j < dpSize; j++)
//         {
//             int value = dp[j] + nums[i];
//             if (value == target)
//                 return true;

//             dp.push_back(value);
//         }
//     }

//     return false;
// }

// using dp
bool canPartition(vector<int> &nums)
{
    int target = 0;

    for (int i = 0; i < nums.size(); i++)
        target += nums[i];

    if (target % 2 != 0)
        return false;

    target /= 2;

    int n = nums.size() + 1;
    int m = target + 1;

    bool **dp = new bool *[n];

    for (int i = 0; i < n; i++)
        dp[i] = new bool[m];

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            dp[y][x] = false;
            if (x == 0)
                dp[y][x] = true;
            if (y == 0)
                dp[y][x] = false;
            if (x == y)
                dp[y][x] = true;
        }
    }

    for (int y = 1; y < n; y++)
    {
        for (int x = 1; x < m; x++)
        {
            if (x >= nums[y - 1])
                dp[y][x] = dp[y - 1][x] || dp[y - 1][x - nums[y - 1]];
            else
                dp[y][x] = dp[y - 1][x];
        }
    }

    return dp[n - 1][m - 1];
}