#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<int> &candidates, int idx, int target, vector<int> &container)
    {

        if (target == 0)
        {
            this->res.push_back(container);
            return;
        }

        if (idx >= candidates.size() || target < 0)
        {
            return;
        }

        // picked
        container.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], container);

        container.pop_back();
        // not picked
        solve(candidates, idx + 1, target, container);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> container;
        solve(candidates, 0, target, container);
        return this->res;
    }
};

int main()
{
    vector<int> candidates = {3, 2, 1, 4};
    Solution sol;

    vector<vector<int>> res = sol.combinationSum(candidates, 9);

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