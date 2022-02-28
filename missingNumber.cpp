#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sumOfAp = n * (n + 1) / 2;

        for (int &i : nums)
            sumOfAp -= i;

        return sumOfAp;
    }
};

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution sol;

    cout << sol.missingNumber(nums);
    return 0;
}