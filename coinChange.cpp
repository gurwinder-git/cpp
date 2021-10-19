#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int change(int amount, vector<int> &coins);

int main()
{
    vector<int> coins = {1, 2, 3};
    cout << change(50, coins);

    return 0;
}
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++)
        for (int j = coins[i]; j < dp.size(); j++)
            dp[j] += dp[j - coins[i]];

    return dp[amount];
}