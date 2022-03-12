#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums);

class Solution
{
public:
    int solve(vector<int> &nums, int i, vector<int> &memo)
    {

        if (i == nums.size() - 1)
        {
            return nums[i];
        }

        if (i >= nums.size())
        {
            return 0;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        // pick
        int left = solve(nums, i + 2, memo) + nums[i];
        // non pick
        int right = solve(nums, i + 1, memo) + 0;

        memo[i] = max(left, right);
        return memo[i];
    }

    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3, 2, 4};
    Solution sol;
    cout << sol.rob(nums);

    // cout << "max rob: " << rob(nums);
    return 0;
}

// dp
int rob(vector<int> &nums)
{
    int size = nums.size();
    if (size == 1)
        return nums[0];

    else if (size == 2)
        return max(nums[0], nums[1]);

    vector<int> dp(size);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < size; i++)
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);

    return dp[size - 1];
}