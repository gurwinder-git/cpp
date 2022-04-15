#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // tco = totalCellOccuppied
    void solve(vector<int> &nums, vector<vector<vector<int>>> &ans, int i, vector<vector<int>> &container, int tco, int k)
    {
        if (i >= nums.size())
        {
            if (tco == k)
            {
                ans.push_back(container);
            }
            return;
        }

        for (int j = 0; j < container.size(); j++)
        {
            if (container[j].size() > 0)
            {
                container[j].push_back(nums[i]);
                solve(nums, ans, i + 1, container, tco, k);
                container[j].pop_back();
            }
            else
            {
                container[j].push_back(nums[i]);
                solve(nums, ans, i + 1, container, tco + 1, k);
                container[j].pop_back();
                break;
            }
        }
    }
    vector<vector<vector<int>>> partitionKSubsets(vector<int> &nums, int k)
    {
        vector<vector<int>> container(k, vector<int>());
        vector<vector<vector<int>>> ans;
        solve(nums, ans, 0, container, 0, k);
        return ans;
    }
};

int main()
{

    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    Solution sol;
    vector<vector<vector<int>>> ans = sol.partitionKSubsets(nums, k);

    for (vector<vector<int>> &A2 : ans)
    {
        cout << "[ ";
        for (vector<int> &A1 : A2)
        {
            cout << "[ ";
            for (int i : A1)
            {
                cout << i << "  ";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
    return 0;
}