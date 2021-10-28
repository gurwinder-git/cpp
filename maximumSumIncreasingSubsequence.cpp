#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSumIS(vector<int> &nums);

int main()
{

    vector<int> nums = {1, 101, 2, 3, 100};
    cout << maxSumIS(nums);

    return 0;
}

int maxSumIS(vector<int> &nums)
{
    vector<int> dp(nums.size());

    int maxSum = nums[0];
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int currMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                currMax = max(currMax, dp[j]);
        }
        dp[i] = currMax + nums[i];
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}