#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int canJumpII(vector<int> &nums);

int main()
{
    vector<int> nums = {3, 5, 2, 1, 4, 3, 0, 1, 2, 3};
    cout << "total jumps: " << canJumpII(nums);
    return 0;
}

// brutr force
//  int solve(int currPos, vector<int> &nums)
//  {
//      if (currPos >= nums.size() - 1)
//          return 0;

//     int maxJump = currPos + nums[currPos];

//     int minJumps = 1001;
//     for (int i = currPos + 1; i <= maxJump; i++)
//     {
//         minJumps = min(minJumps, 1 + solve(i, nums));
//     }

//     return minJumps;
// }

// int canJumpII(vector<int> &nums)
// {
//     return solve(0, nums);
// }

// memorization
// int solve(int currPos, vector<int> &nums, vector<int> &dp)
// {
//     if (currPos >= nums.size() - 1)
//         return 0;

//     if (dp[currPos] != -1)
//         return dp[currPos];

//     int maxReach = currPos + nums[currPos];

//     int minJumps = 9999999;
//     for (int i = currPos + 1; i <= maxReach; i++)
//     {
//         minJumps = min(minJumps, 1 + solve(i, nums, dp));
//     }

//     return dp[currPos] = minJumps;;
// }

// int canJumpII(vector<int> &nums)
// {
//     vector<int> dp(nums.size(), -1);
//     int ans = solve(0, nums, dp);
//     return ans;
// }

// greedy method

// int canJumpII(vector<int> &nums)
// {
//     int minJumps = 0;

//     int i = 0;

//     while (i < nums.size() - 1)
//     {
//         int checkUpTo = i + nums[i];

//         if (checkUpTo >= nums.size() - 1)
//             return minJumps + 1;

//         i++;

//         int goodIndex = checkUpTo;
//         int sum = nums[checkUpTo] + checkUpTo;

//         while (i < checkUpTo)
//         {
//             if (nums[i] + i >= sum)
//             {
//                 sum = nums[i] + i;
//                 goodIndex = i;
//             }

//             i++;
//         }
//         minJumps++;
//         i = goodIndex;
//     }

//     return minJumps;
// }

// another greedy

int canJumpII(vector<int> &nums)
{
    int currMaxReach = 0;
    int bestOf = currMaxReach;
    int jumps = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        currMaxReach = max(currMaxReach, i + nums[i]);

        if (i == bestOf)
        {
            jumps++;
            bestOf = currMaxReach;
        }
    }

    return jumps;
}