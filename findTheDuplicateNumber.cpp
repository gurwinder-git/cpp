#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() > 1)
        {

            int slow = nums[0];
            int fast = nums[nums[0]];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;

            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }

            return slow;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 3, 4, 2, 1};

    Solution sol;
    cout << sol.findDuplicate(nums);

    return 0;
}