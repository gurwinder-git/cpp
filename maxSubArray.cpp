#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums);
int main()
{
    vector<int> nums = {-1, -10, 3, 4, -1};
    cout << maxSubArray(nums);
    return 0;
}
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int sum = nums[0];

    for (auto it = nums.begin() + 1; it != nums.end(); it++)
    {
        sum = max(*it, (sum + *it));
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}