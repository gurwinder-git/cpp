#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums, int target = 0)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size() - 2)
        {
            int newTarget = target - nums[i];

            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                if (nums[start] + nums[end] > newTarget)
                {
                    end--;
                }
                else if (nums[start] + nums[end] < newTarget)
                {
                    start++;
                }
                else
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    int newStart = start + 1;
                    int newEnd = end - 1;

                    while (newStart < end && nums[start] == nums[newStart])
                        newStart++;

                    while (newEnd > start && nums[end] == nums[newEnd])
                        newEnd--;

                    start = newStart;
                    end = newEnd;
                }
            }
            int newI = i + 1;

            while (newI < nums.size() - 2 && nums[i] == nums[newI])
                newI++;
            i = newI;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution sol;

    cout << "[";
    for (auto v : sol.threeSum(nums))
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