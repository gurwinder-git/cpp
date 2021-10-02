#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int> &nums);
int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
    return 0;
}
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());

    int maxlenght = 1;
    int curruntMaxLenght = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;

        if ((nums[i] - 1) == nums[i - 1])
            curruntMaxLenght++;
        else
        {
            maxlenght = max(maxlenght, curruntMaxLenght);
            curruntMaxLenght = 1;
        }
    }
    return max(maxlenght, curruntMaxLenght);
}