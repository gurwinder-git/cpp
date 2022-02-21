#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> combination;

    void solve(vector<int> &nums, int start, int k)
    {
        if (k == 0)
        {
            ans.push_back(combination);
            return;
        }
        if (start >= nums.size())
        {
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            combination.push_back(nums[i]);
            solve(nums, i + 1, k - 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = i + 1;

        solve(nums, 0, k);
        return ans;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> combination = sol.combine(4, 2);

    for (auto &v : combination)
    {
        cout << "[";
        for (int &i : v)
        {
            cout << " " << i << " ";
        }
        cout << "]";
    }
    return 0;
}