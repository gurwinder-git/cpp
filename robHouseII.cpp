#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int robHouseII(vector<int> &nums);
int main()
{
    vector<int> nums = {4, 6, 7, 4, 2, 5, 8};
    cout << "maximum rob: " << robHouseII(nums);
    return 0;
}

int robHouseII(vector<int> &nums)
{
    switch (nums.size())
    {
    case 1:
        return nums[0];
    case 2:
        return max(nums[0], nums[1]);
    // case 3:
    //     return max({nums[0], nums[1], nums[2]});
    default:
        break;
    }

    vector<int> dp(nums.size() - 1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size() - 1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    int ans = dp[nums.size() - 2];

    dp[0] = nums[1];
    dp[1] = max(nums[1], nums[2]);

    for (int i = 3; i < nums.size(); i++)
    {
        dp[i - 1] = max(dp[i - 2], dp[i - 3] + nums[i]);
    }

    return max(ans, dp[nums.size() - 2]);
}