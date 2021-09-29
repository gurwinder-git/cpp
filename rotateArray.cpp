#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int> &nums, int k);
int main()
{
    vector<int> nums = {-1, -100, 3, 99};
    rotateArray(nums, 2);

    for (int num : nums)
        cout << num << " ";
    return 0;
}
void rotateArray(vector<int> &nums, int k)
{
    k = k % nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}