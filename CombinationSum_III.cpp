#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &container, int start, int k, int target, vector<vector<int>> &ans)
    {
        if (target == 0 && container.size() == k)
        {
            ans.push_back(container);
            return;
        }

        if (target < 0 || container.size() > k)
        {
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            container.push_back(i);
            backtrack(container, i + 1, k, target - i, ans);
            container.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<vector<int>> ans;
        vector<int> container;

        backtrack(container, 1, k, target, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(3, 11);

    for (vector<int> &v : ans)
    {
        cout << "[ ";
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}