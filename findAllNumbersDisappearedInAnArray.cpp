#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;

        for (int &i : nums)
        {
            // int idx = i < 0 ? (i * (-1)) : i;
            // idx--;
            int idx = abs(i) - 1;
            if (nums[idx] < 0)
                continue;
            nums[idx] *= -1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;

    vector<int> ans = sol.findDisappearedNumbers(nums);

    for (int i : ans)
        cout << i << "  ";
    return 0;
}