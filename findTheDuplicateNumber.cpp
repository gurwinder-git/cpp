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

            // one pase outside loop
            // to      //from
            int slow = nums[nums[0]];
            int fast = nums[nums[nums[0]]];

            while (slow != fast)
            {
                // to  //from
                slow = nums[slow];
                fast = nums[fast];
                fast = nums[fast];
            }

            slow = nums[0];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
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