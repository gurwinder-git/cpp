#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int currentOnes = 0;
        int maxOnes = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                currentOnes++;
                maxOnes = max(maxOnes, currentOnes);
            }
            else
            {
                currentOnes = 0;
            }
        }

        return maxOnes;
    }
};

int main()
{
    vector<int> nums({1, 1, 0, 1, 1, 1});
    Solution sol;

    cout << sol.findMaxConsecutiveOnes(nums);

    return 0;
}