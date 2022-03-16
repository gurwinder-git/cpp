#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int> &nums);

class Solution
{
public:
    // memo
    int solve(vector<int> &nums, int i, int prei, int **dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (prei != -1 && dp[prei][i] != -1)
        {
            return dp[prei][i];
        }

        // pick
        int left = 0;
        if (prei == -1 || nums[prei] < nums[i])
        {
            left = 1 + solve(nums, i + 1, i, dp);
        }

        // not pick
        int right = solve(nums, i + 1, prei, dp);

        if (prei == -1)
        {
            return max(left, right);
        }
        else
        {
            return dp[prei][i] = max(left, right);
        }
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int **dp = new int *[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            (*(dp + i)) = new int[nums.size()];
            for (int j = 0; j < nums.size(); j++)
            {
                dp[i][j] = -1;
                // cout << *((*(dp + i)) + j) << "  ";
            }
        }

        return solve(nums, 0, -1, dp);
    }
};

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    cout << sol.lengthOfLIS(nums);

    return 0;
}

// old
// int lengthOfLIS(vector<int> &nums)
// {
//     short int maxLenght = 1;

//     vector<short int> dp(nums.size());
//     dp[0] = 1;

//     for (int i = 1; i < nums.size(); i++)
//     {
//         short int currMax = 0;
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] > nums[j])
//                 currMax = max(currMax, dp[j]);
//         }
//         dp[i] = currMax + 1;
//         maxLenght = max(maxLenght, dp[i]);
//     }
//     return maxLenght;
// }