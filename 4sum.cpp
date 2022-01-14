#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        if (nums.size() < 4)
            return res;

        for (int i = 0; i < nums.size() - 3; i++)
        {
            int target3 = target - nums[i];

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int target2 = target3 - nums[j];

                int start = j + 1;
                int end = nums.size() - 1;

                while (start < end)
                {
                    if (nums[start] + nums[end] < target2)
                        start++;
                    else if (nums[start] + nums[end] > target2)
                        end--;
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});

                        start++;
                        while (start < end && res.back()[2] == nums[start])
                            start++;

                        end--;
                        while (end > start && res.back()[3] == nums[end])
                            end--;
                    }
                }

                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;
    vector<vector<int>> res = sol.fourSum(nums, target);

    cout << "[";
    for (auto v : res)
    {
        cout << "[  ";
        for (int i : v)
        {
            cout << i << "  ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}
