#include <iostream>
#include <vector>
using namespace std;

void sortColor(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 2, 0, 1, 0, 2, 2, 0, 0};
    sortColor(nums);
    for (int num : nums)
        cout << num;
    return 0;
}

void sortColor(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[mid++], nums[low++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(nums[mid], nums[high--]);
            break;
        }
    }
}