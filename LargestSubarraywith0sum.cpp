#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        mp.insert({0, -1});

        int ans = 0;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];

            // if sum exist before
            unordered_map<int, int>::iterator itr = mp.find(currentSum);
            if (itr != mp.end())
            {
                ans = max(ans, i - itr->second);
            }
            else
            {
                mp.insert({currentSum, i});
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    Solution sol;

    cout << sol.maxLen(nums);
    return 0;
}