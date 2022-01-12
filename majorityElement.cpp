#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // O(n) space complexity

    //  int majorityElement(vector<int> &nums)
    //  {
    //      int ans;
    //      unordered_map<int, int> mp;

    //     for (int i : nums)
    //     {
    //         mp[i]++;
    //     }
    //     int size = nums.size() / 2;

    //     for (pair<int, int> p : mp)
    //     {
    //         if (p.second > size)
    //         {
    //             ans = p.first;
    //         }
    //     }

    //     return ans;
    // }

    // O(1) space complexity

    int majorityElement(vector<int> &nums)
    {
        int val = nums.at(0);
        int totalElementsWhichAreNotPair = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (totalElementsWhichAreNotPair == 0)
            {
                val = nums[i];
                totalElementsWhichAreNotPair = 1;
            }
            else if (val != nums[i])
            {
                totalElementsWhichAreNotPair--;
            }
            else
            {
                totalElementsWhichAreNotPair++;
            }
        }

        return val;
    }
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;

    cout << sol.majorityElement(nums);

    return 0;
}
