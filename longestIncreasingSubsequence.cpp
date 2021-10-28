#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int> &nums);

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);

    return 0;
}

int lengthOfLIS(vector<int> &nums)
{
    short int maxLenght = 1;

    vector<short int> dp(nums.size());
    dp[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        short int currMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                currMax = max(currMax, dp[j]);
        }
        dp[i] = currMax + 1;
        maxLenght = max(maxLenght, dp[i]);
    }
    return maxLenght;
}