#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2, -1);

        // find left boundery
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                res[0] = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        low = 0;
        high = nums.size() - 1;

        // find boundery
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                res[1] = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 8, 8, 8, 8, 8, 10};

    Solution sol;

    vector<int> res = sol.searchRange(nums, 8);
    cout << res[0] << ", ";
    cout << res[1];
    return 0;
}