#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // using left and right array
    // vector<int> productExceptSelf(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<int> left(n), right(n);
    //     left[0] = nums[0];
    //     right[n - 1] = nums[n - 1];

    //     // left Array
    //     for (int i = 1; i < n; i++)
    //     {
    //         left[i] = left[i - 1] * nums[i];
    //     }

    //     // right array
    //     for (int i = n - 2; i >= 0; i--)
    //     {
    //         right[i] = right[i + 1] * nums[i];
    //     }

    //     vector<int> ans(n);

    //     for (int i = 1; i < n - 1; i++)
    //     {
    //         ans[i] = left[i - 1] * right[i + 1];
    //     }

    //     ans[0] = right[1];
    //     ans[n - 1] = left[n - 2];

    //     return ans;
    // }

    // using only right array
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // right array
        vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] * nums[i];

        // left product
        int leftProduct = 1;

        vector<int> ans(n);
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = leftProduct * right[i + 1];
            leftProduct *= nums[i];
        }
        ans[n - 1] = leftProduct;

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    Solution sol;

    vector<int> res = sol.productExceptSelf(nums);

    for (int &i : res)
    {
        cout << i << "  ";
    }

    return 0;
}