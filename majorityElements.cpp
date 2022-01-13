#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> majorityElements(vector<int> &nums);

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int val1 = nums[0];
        int count1 = 1;
        int val2 = nums[0];
        int count2 = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == val1)
            {
                count1++;
            }
            else if (nums[i] == val2)
            {
                count2++;
            }
            else
            {
                if (count1 == 0)
                {
                    count1 = 1;
                    val1 = nums[i];
                }
                else if (count2 == 0)
                {
                    count2 = 1;
                    val2 = nums[i];
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
        }

        count1 = count2 = 0;

        // count frequency

        for (int i : nums)
        {
            if (val1 == i)
            {
                count1++;
            }
            else if (val2 == i)
            {
                count2++;
            }
        }

        vector<int> ans;

        if (count1 > nums.size() / 3)
            ans.push_back(val1);
        if (count2 > nums.size() / 3)
            ans.push_back(val2);

        return ans;
    }

    // O(n) space
    //  vector<int> majorityElements(vector<int> &nums)
    //  {
    //      unordered_map<int, int> frequencyOfElements;
    //      vector<int> res;

    //     int k = nums.size() / 3;

    //     for (int num : nums)
    //         frequencyOfElements[num]++;

    //     for (pair<int, int> obj : frequencyOfElements)
    //     {
    //         if (obj.second > k)
    //             res.push_back(obj.first);
    //     }

    //     return res;
    // }
};

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 2, 1, 2, 1, 2, 1, 4};
    Solution sol;
    vector<int> ans = sol.majorityElement(nums);
    cout << "[";
    for (int num : ans)
        cout << " " << num << " ";
    cout << " ]";

    return 0;
}
