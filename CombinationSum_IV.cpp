#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // memo
    int solve(vector<int> &nums, int target, vector<int> &memo)
    {
        if (target == 0)
        {
            return 1;
        }
        if (target < 0)
        {
            return 0;
        }

        if (memo[target] != -1)
        {
            return memo[target];
        }

        int ans = 0;

        for (int &num : nums)
        {
            ans += solve(nums, target - num, memo);
        }

        return memo[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> memo(target + 1, -1);
        return solve(nums, target, memo);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;

    Solution sol;
    cout << sol.combinationSum4(nums, target);

    return 0;
}