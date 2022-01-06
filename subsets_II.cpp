#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, int idx, vector<int> &container)
    {
        if (idx >= nums.size())
        {
            res.push_back(container);
            return;
        }

        // picking

        container.push_back(nums[idx]);
        dfs(nums, idx + 1, container);
        // not picking
        container.pop_back();

        int nextIndexOfUniqueElement = idx + 1;

        while (nextIndexOfUniqueElement < nums.size() && nums[idx] == nums[nextIndexOfUniqueElement])
        {
            nextIndexOfUniqueElement++;
        }

        dfs(nums, nextIndexOfUniqueElement, container);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> container;
        dfs(nums, 0, container);
        return this->res;
    }
};

int main()
{
    vector<int> candidates = {3, 2, 1, 4};
    Solution sol;

    vector<vector<int>> res = sol.subsetsWithDup(candidates);

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