#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void solve(vector<int> &candidates, int idx, int target, vector<int> &ans)
    {
        if (target == 0)
        {
            this->res.push_back(ans);
            return;
        }

        if (idx >= candidates.size() || target < 0)
        {
            return;
        }

        // picking element
        ans.push_back(candidates[idx]);
        solve(candidates, idx + 1, target - candidates[idx], ans);

        // not picing element
        ans.pop_back();
        int nextIndexOfUniqueElemet = idx + 1;

        while (nextIndexOfUniqueElemet < candidates.size() && candidates[idx] == candidates[nextIndexOfUniqueElemet])
        {
            nextIndexOfUniqueElemet++;
        }

        solve(candidates, nextIndexOfUniqueElemet, target, ans);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        solve(candidates, 0, target, ans);
        return res;
    }
};

int main()
{
    vector<int> candidates = {3, 2, 2, 4};
    Solution sol;

    vector<vector<int>> res = sol.combinationSum2(candidates, 8);

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