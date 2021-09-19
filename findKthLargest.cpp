#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {-1, 2, 0};
    cout << findKthLargest(nums, 2);
    return 0;
}

int findKthLargest(vector<int> &nums, int k)
{
    int tempLargest = nums[0];
    int tempMin = nums[0];
    vector<int> elementsIndexes;
    int tempIndex = 0;
    // cout << nums.size() << endl;

    while (k > 0)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (count(elementsIndexes.begin(), elementsIndexes.end(), i))
            {
                i++;
                continue;
            }

            if (tempLargest <= nums[i])
            {
                tempLargest = nums[i];
                tempIndex = i;
            }

            if (tempMin > nums[i])
                tempMin = nums[i];

            i++;
        }
        elementsIndexes.push_back(tempIndex);
        tempLargest = tempMin;

        k--;
    }

    return nums[elementsIndexes.back()];
}