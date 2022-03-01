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