#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int ans;
    int minCoins(int coins[], int M, int V)
    {
        this->ans = INT_MAX;
    }

    // TLE
    //  int ans;

    // void solve(int coins[], int idx, int n, int v, int totalCoinsUsed)
    // {
    //     if (v == 0)
    //     {
    //         this->ans = min(this->ans, totalCoinsUsed);
    //     }
    //     if (idx >= n || v < 0)
    //         return;

    //     solve(coins, idx, n, v - coins[idx], totalCoinsUsed + 1);
    //     solve(coins, idx + 1, n, v, totalCoinsUsed);
    // }
    // int minCoins(int coins[], int M, int V)
    // {
    //     this->ans = INT_MAX;
    //     solve(coins, 0, M, V, 0);
    //     if (this->ans == INT_MAX)
    //         return -1;
    //     return this->ans;
    // }
};

int main()
{

    int coins[] = {25, 10, 5};
    int V = 30, M = 3;

    Solution sol;

    cout << "Minimun coins needed: " << sol.minCoins(coins, M, V);

    return 0;
}