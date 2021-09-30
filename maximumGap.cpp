#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximunGap(vector<int> &nums);
int main()
{
    vector<int> nums = {-1, -10, 3, 4, -1};
    cout << maximunGap(nums);
}
int maximunGap(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int max = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int diff = nums[i] - nums[i - 1];
        if (diff > max)
            max = diff;
    }
    return max;
}
