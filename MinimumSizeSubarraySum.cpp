#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minSubArrayLen(vector<int> &nums, int target);
int main()
{
    vector<int> nums = {1, 2, 3, 5, 67};
    cout << minSubArrayLen(nums, 7);
    return 0;
}

int minSubArrayLen(vector<int> &nums, int target)
{
    int minLenght = INT_MAX;
    int left = 0;

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        while (sum >= target)
        {
            minLenght = min(minLenght, (i + 1) - left);
            sum -= nums[left];
            left++;
        }
    }

    return (minLenght == INT_MAX ? 0 : minLenght);
}