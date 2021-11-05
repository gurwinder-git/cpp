#include <iostream>
#include <vector>

using namespace std;

int uniquesPaths(int m, int n);
int main()
{
    int m = 4, n = 4;
    cout << "unique paths of " << m << " * " << n << " Grid: " << uniquesPaths(m, n);
    return 0;
}

int uniquesPaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int y = m - 2; y >= 0; y--)
    {
        for (int x = n - 2; x >= 0; x--)
        {
            dp[y][x] = dp[y][x + 1] + dp[y + 1][x];
        }
    }

    return dp[0][0];
}