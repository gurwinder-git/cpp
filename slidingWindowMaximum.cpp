#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        int i = 0;

        for (; i < k; i++)
        {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
        }

        // cout << i << endl;

        ans.push_back(nums[dq.front()]);

        for (; i < nums.size(); i++)
        {
            // remove from back until we get small element

            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (dq.front() <= i - k)
                dq.pop_front();

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

    // brute force O(k * n) TLE
    // vector<int> maxSlidingWindow(vector<int> &nums, int k)
    // {
    //     vector<int> ans;

    //     for (int i = 0; i <= nums.size() - k; i++)
    //     {
    //         int j = i;
    //         int range = j + k;
    //         int maxNum = INT_MIN;

    //         while (j < range)
    //         {
    //             maxNum = max(maxNum, nums[j]);
    //             j++;
    //         }
    //         ans.push_back(maxNum);
    //     }
    //     return ans;
    // }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, 3);

    cout << "[  ";
    for (int i : ans)
        cout << i << "  ";
    cout << "]";

    return 0;
}