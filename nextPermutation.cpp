#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pivot = nums.size() - 2;

        for (; pivot >= 0; pivot--)
        {
            if (nums[pivot] >= nums[pivot + 1])
            {
            }
            else
            {
                break;
            }
        }

        if (pivot < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int indexOfGreatorElementThanPivot = nums.size() - 1;

            for (; indexOfGreatorElementThanPivot > pivot; indexOfGreatorElementThanPivot--)
            {
                if (nums[indexOfGreatorElementThanPivot] > nums[pivot])
                {
                    break;
                }
            }

            swap(nums[pivot], nums[indexOfGreatorElementThanPivot]);

            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};

int main()
{
    // vector<int> num = {3, 1, 7, 5, 4, 2, 1};
    vector<int> num = {3, 2, 1};

    Solution sol;

    sol.nextPermutation(num);

    for (int i : num)
        cout << i << " ";

    return 0;
}