#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        int i = 0;
        int j = 0;

        while (i < nums.size())
        {
            while (j < nums.size() && nums[j] == nums[i])
            {
                j++;
            }

            nums[k] = nums[i];
            k++;
            i = j;
        }

        return k;
    }
};

int main()
{
    vector<int> nums({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    Solution sol;

    int newLenght = sol.removeDuplicates(nums);

    // updated array
    for (int i = 0; i < newLenght; i++)
        cout << nums.at(i) << " ";

    return 0;
}