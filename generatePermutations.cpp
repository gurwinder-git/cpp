#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // using O(n) space complexity
    //  vector<vector<int>> res;

    // void solve(vector<int> &nums, vector<int> &perm, vector<bool> &hash)
    // {
    //     if (perm.size() == nums.size())
    //     {
    //         this->res.push_back(perm);
    //         return;
    //     }

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (hash[i] == false)
    //         {
    //             hash[i] = true;
    //             perm.push_back(nums[i]);

    //             solve(nums, perm, hash);

    //             perm.pop_back();
    //             hash[i] = false;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int> &nums)
    // {
    //     vector<bool> hash(nums.size(), false);
    //     vector<int> perm;
    //     this->solve(nums, perm, hash);
    //     return this->res;
    // }

    // using O(1) space complexity

    // vector<vector<int>> res;

    // void solve(vector<int> nums, vector<int> &asf)
    // {
    //     if (nums.size() == 0)
    //     {
    //         this->res.push_back(asf);
    //         return;
    //     }

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         vector<int> newNums;
    //         newNums.insert(newNums.end(), nums.begin(), nums.begin() + i);
    //         newNums.insert(newNums.end(), nums.begin() + i + 1, nums.end());
    //         asf.push_back(nums[i]);
    //         solve(newNums, asf);
    //         asf.pop_back();
    //     }
    // }

    // vector<vector<int>> permute(vector<int> &nums)
    // {

    //     vector<int> asf;
    //     this->solve(nums, asf);
    //     return res;
    // }

    // solution 3

    vector<vector<int>> res;

    void solve(vector<int> &nums, int pointer)
    {
        if (pointer >= nums.size())
        {
            this->res.push_back(nums);
            return;
        }

        for (int i = pointer; i < nums.size(); i++)
        {
            swap(nums[i], nums[pointer]);
            solve(nums, pointer + 1);
            swap(nums[i], nums[pointer]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        this->solve(nums, 0);
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution sol;

    vector<vector<int>> res = sol.permute(nums);

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