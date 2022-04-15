#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
    }

    // My brute force TLE
    //  int ans;
    //  void solve(vector<int> &coins, int i, int amount, int coinsCount)
    //  {
    //      if (amount == 0)
    //      {
    //          ans = min(ans, coinsCount);
    //          return;
    //      }
    //      if (amount < 0 || i >= coins.size())
    //      {
    //          return;
    //      }

    //     // pick
    //     solve(coins, i, amount - coins[i], coinsCount + 1);

    //     // not pick
    //     solve(coins, i + 1, amount, coinsCount);
    // }

    // int coinChange(vector<int> &coins, int amount)
    // {
    //     ans = INT_MAX;
    //     sort(coins.begin(), coins.end(), greater<>()); //no need of sorting
    //     solve(coins, 0, amount, 0);
    //     return ans == INT_MAX? -1: ans;
    // }
};

int main()
{
    vector<int> coins = {1, 2, 5};

    Solution sol;

    cout << sol.coinChange(coins, 11);

    return 0;
}
