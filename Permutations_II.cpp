#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void solve(vector<int> &nums, vector<int> &asf, vector<bool> &hash)
    {
        if (asf.size() == nums.size())
        {
            this->res.push_back(asf);
            return;
        }

        int i = 0;
        while (i < nums.size())
        {
            if (hash[i] == false)
            {
                hash[i] = true;
                asf.push_back(nums[i]);
                solve(nums, asf, hash);
                asf.pop_back();
                hash[i] = false;

                int nextIndexOfUniqueElement = i + 1;

                while (nextIndexOfUniqueElement < nums.size() && nums[nextIndexOfUniqueElement] == nums[i])
                {
                    nextIndexOfUniqueElement++;
                }
                i = nextIndexOfUniqueElement;
            }
            else
            {
                i++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> asf;
        vector<bool> hash(nums.size(), false);
        solve(nums, asf, hash);
        return this->res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2};
    Solution sol;

    vector<vector<int>> res = sol.permuteUnique(nums);

    cout << "[";
    for (auto v : res)
    {
        cout << "[";
        for (int i : v)
        {
            cout << " " << i << " ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}