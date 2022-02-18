#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map; // sum - frequency
        map.insert({0, 1});
        int ans = 0;
        int y = 0;

        for (int &num : nums)
        {
            y += num;

            if (map.find(y - k) != map.end())
            {
                ans += map[y - k];
            }
            map[y]++;
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 1, 1};

    Solution sol;
    cout << sol.subarraySum(nums, 2);
    return 0;
}