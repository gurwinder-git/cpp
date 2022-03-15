#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProduct(vector<int> &nums);

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int om = INT_MIN;
        int cm = 1;

        // right to left
        for (int i = 0; i < n; i++)
        {
            cm *= nums[i];
            om = max(om, cm);

            if (cm == 0)
            {
                cm = 1;
            }
        }

        // left to right
        cm = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            cm *= nums[i];
            om = max(om, cm);

            if (cm == 0)
            {
                cm = 1;
            }
        }

        return om;
    }
};
int main()
{
    vector<int> nums = {-1, -10, 3, -9};
    Solution sol;
    cout << sol.maxProduct(nums);
    // cout << maxProduct(nums);
}

// old
//  int maxProduct(vector<int> &nums)
//  {
//      int maxProduct = INT_MIN;

//     int product = 1;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         product = product * nums[i];
//         if (product > maxProduct)
//             maxProduct = product;
//         if (product == 0)
//             product = 1;
//     }
//     product = 1;
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         product = product * nums[i];
//         if (product > maxProduct)
//             maxProduct = product;
//         if (product == 0)
//             product = 1;
//     }
//     return maxProduct;
// }