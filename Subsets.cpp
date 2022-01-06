#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &arr, int idx, vector<int> &subsets)
    {
        if (idx >= arr.size())
        {
            this->res.push_back(subsets);
            return;
        }

        // picking
        subsets.push_back(arr[idx]);
        dfs(arr, idx + 1, subsets);
        // not picking
        subsets.pop_back();
        dfs(arr, idx + 1, subsets);
    }
    vector<vector<int>> subsets(vector<int> arr)
    {
        vector<int> subsets;
        dfs(arr, 0, subsets);
        return res;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1};
    Solution sol;

    vector<vector<int>> res = sol.subsets(nums);

    cout << "[";

    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << " " << i << " ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}