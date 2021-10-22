#include <iostream>

using namespace std;

int numTrees(int n);

int main()
{
    cout << numTrees(4);

    return 0;
}

// using recursion
// int numTrees(int n)
// {
//     if (n == 0 || n == 1)
//         return 1;

//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += numTrees(i) * numTrees(n - i - 1);

//     return sum;
// }

// using memorization
// int memorization(int n, int dp[])
// {
//     if (n == 0 || n == 1)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];

//     int sum = 0;

//     for (int i = 0; i < n; i++)
//         sum += memorization(i, dp) * memorization(n - i - 1, dp);

//     return dp[n] = sum;
// }

// int numTrees(int n)
// {
//     int *dp = new int[n + 1];
//     for (int i = 0; i <= n; i++)
//         dp[i] = -1;

//     int res = memorization(n, dp);
//     delete[] dp;
//     return res;
// }

// using dynamic programming

int numTrees(int n)
{
    int *dp = new int[n + 1];
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        int left = 0;
        int right = i - 1;
        int sum = 0;
        while (left < i)
        {
            sum += dp[left] * dp[right];
            left++;
            right--;
        }
        dp[i] = sum;
    }

    return dp[n];
}
