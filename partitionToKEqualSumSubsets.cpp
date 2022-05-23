#include <iostream>
#include <vector>

using namespace std;

// TLEpermu
class Solution
{
public:
    // tco = totalCellOccuppied
    bool solve(vector<int> &nums, int i, vector<vector<int>> &container, int tco, int k, int target)
    {
        if (i >= nums.size())
        {
            if (tco == k)
            {
                for (vector<int> &v : container)
                {
                    if (v[0] != target)
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        for (int j = 0; j < container.size(); j++)
        {
            if (container[j].size() > 0)
            {
                container[j][0] += nums[i];
                if (solve(nums, i + 1, container, tco, k, target))
                {
                    return true;
                }
                container[j][0] -= nums[i];
            }
            else
            {
                container[j].push_back(nums[i]);
                if (solve(nums, i + 1, container, tco + 1, k, target))
                {
                    return true;
                }
                container[j].pop_back();
                break;
            }
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        vector<vector<int>> container(k, vector<int>());
        int target = 0;
        for (int &i : nums)
            target += i;

        if (target % k != 0)
            return false;

        return solve(nums, 0, container, 0, k, target / k);
    }
};

int main()
{

    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    Solution sol;
    cout << sol.canPartitionKSubsets(nums, k);

    return 0;
}