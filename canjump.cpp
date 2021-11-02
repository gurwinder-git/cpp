#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums);

int main()
{
    vector<int> nums = {3, 2, 2, 0, 1};
    cout << (canJump(nums) ? "yes, you can jump" : "no you can't jump");
    return 0;
}

// brute force recursion
// bool solve(int currPos, vector<int> &nums)
// {
//     if (currPos >= nums.size() - 1)
//         return true;

//     int target = currPos + nums[currPos];

//     for (int k = target; k >= currPos + 1; k--)
//         if (solve(k, nums))
//             return true;

//     return false;
// }

// bool canJump(vector<int> &nums)
// {
//     return solve(0, nums);
// }

// gredy method
bool canJump(vector<int> &nums)
{
    int lastGoodIndex = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (i + nums[i] >= lastGoodIndex)
            lastGoodIndex = i;
    }

    return lastGoodIndex == 0;
}
