#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &nums);
int main()
{
    vector<int> nums = {2, 3, 5, 6, 7, 4, 3, 2, 1};
    vector<int> res = findDuplicates(nums);

    for (int num : res)
        cout << num << " ";
    return 0;
}
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        int indexValue = abs(nums[i]) - 1;
        //nigate the indexvalue
        nums[indexValue] = -nums[indexValue];

        if (nums[indexValue] > 0)
            res.push_back(abs(nums[i]));
    }
    return res;
}