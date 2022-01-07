#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void solve(vector<int> &nums, vector<int> &perm, vector<bool> &hash)
    {
        if (perm.size() == nums.size())
        {
            this->res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash[i] == false)
            {
                hash[i] = true;
                perm.push_back(nums[i]);

                solve(nums, perm, hash);

                perm.pop_back();
                hash[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> hash(nums.size(), false);
        vector<int> perm;
        this->solve(nums, perm, hash);
        return this->res;
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