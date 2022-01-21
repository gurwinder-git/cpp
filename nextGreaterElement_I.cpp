#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // O(2n) time complexity
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> stk;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() < nums2[i])
            {
                stk.pop();
            }

            if (stk.empty())
            {
                mp.insert({nums2[i], -1});
            }
            else
            {
                mp.insert({nums2[i], stk.top()});
            }
            stk.push(nums2[i]);
        }

        vector<int> ans(nums1.size());

        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = mp.at(nums1[i]);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    cout << "[ ";
    for (int i : ans)
    {
        cout << i << "  ";
    }
    cout << "]";

    return 0;
}