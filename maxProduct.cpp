#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProduct(vector<int> &nums);
int main()
{
    vector<int> nums = {-1, -10, 3, -9};
    cout << maxProduct(nums);
}

int maxProduct(vector<int> &nums)
{
    int maxProduct = INT_MIN;

    int product = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        product = product * nums[i];
        if (product > maxProduct)
            maxProduct = product;
        if (product == 0)
            product = 1;
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        product = product * nums[i];
        if (product > maxProduct)
            maxProduct = product;
        if (product == 0)
            product = 1;
    }
    return maxProduct;
}