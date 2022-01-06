#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> res;

    void dfs(vector<int> &arr, int idx, int sum)
    {
        if (idx >= arr.size())
        {
            this->res.push_back(sum);
            return;
        }

        // picking
        dfs(arr, idx + 1, sum + arr[idx]);
        dfs(arr, idx + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        dfs(arr, 0, 0);
        sort(this->res.begin(), this->res.end());
        return res;
    }
};

int main()
{
    vector<int> candidates = {3, 2, 1};
    Solution sol;

    vector<int> res = sol.subsetSums(candidates, 9);

    cout << "[";
    for (auto i : res)
    {

        cout << " " << i << " ";
    }
    cout << "]";

    return 0;
}