#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int nonRepeatedNum = 0;

        for (int num : nums)
        {
            nonRepeatedNum = nonRepeatedNum ^ num;
        }

        return nonRepeatedNum;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 3, 5, 2, 3, 5, 100};
    Solution sol;
    cout << "non repeated num: " << sol.singleNumber(nums);
    return 0;
}