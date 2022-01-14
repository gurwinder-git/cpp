#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];

            if (mp.find(num) != mp.end())
            {
                return {mp[num], i};
            }
            else
            {
                mp.insert(pair<int, int>({nums[i], i}));
            }
        }

        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    Solution sol;

    for (int i : sol.twoSum(nums, 9))
    {
        cout << i << " ";
    }
    return 0;
}