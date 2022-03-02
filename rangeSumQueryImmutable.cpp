#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
    vector<int> preSum;

    NumArray(vector<int> &nums)
    {
        preSum.resize(nums.size());
        preSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return preSum[right];
        }
        else
        {
            return preSum[right] - preSum[left - 1];
        }
    }
};

int main()
{
    vector<int> input = {-2, 0, 3, -5, 2, -1};
    NumArray obj(input);
    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(1, 2) << endl;
    cout << obj.sumRange(2, 3) << endl;
    cout << obj.sumRange(3, 4) << endl;
    cout << obj.sumRange(0, 4) << endl;
    return 0;
}