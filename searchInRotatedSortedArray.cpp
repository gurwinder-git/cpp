#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[low] <= nums[mid]) // if sorted from low to mid
            {
                if (target >= nums[low] && target < nums[mid]) // check range
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else // will sorted from mid to high
            {
                if (target > nums[mid] && target <= nums[high]) // check range
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> rotatedArray = {7, 8, 9, 0, 1, 2, 3, 4};

    Solution sol;

    cout << "index of element: " << sol.search(rotatedArray, 4);
    return 0;
}