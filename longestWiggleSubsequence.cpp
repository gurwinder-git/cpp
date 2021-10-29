#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int> &nums);
int main()
{
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << wiggleMaxLength(nums);
    return 0;
}

int wiggleMaxLength(vector<int> &nums)
{
    int up, down;
    up = down = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            up = down + 1;

        if (nums[i] < nums[i - 1])
            down = up + 1;
    }

    return (up > down ? up : down);
}