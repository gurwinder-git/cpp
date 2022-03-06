#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findFirstPositiveInSortedArray(vector<int> &nums)
    {
        int l = 0, h = nums.size() - 1, ans = nums.size() - 1;

        while (l < h)
        {
            int mid = (l + h) / 2;

            if (nums[mid] >= 0)
            {
                ans = mid;
                h = mid;
            }
            else // nums[mid] < 0
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int idx = 0;
        int i = this->findFirstPositiveInSortedArray(nums);
        int j = i - 1;

        while (i < nums.size() && j >= 0)
        {
            if (abs(nums[i]) <= abs(nums[j]))
            {
                ans[idx] = nums[i] * nums[i];
                i++;
            }
            else
            {
                ans[idx] = nums[j] * nums[j];
                j--;
            }
            idx++;
        }

        while (j >= 0)
        {
            ans[idx] = nums[j] * nums[j];
            j--;
            idx++;
        }

        while (i < nums.size())
        {
            ans[idx] = nums[i] * nums[i];
            i++;
            idx++;
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution sol;

    vector<int> squers = sol.sortedSquares(nums);

    for (int i : squers)
    {
        cout << i << "  ";
    }

    return 0;
}