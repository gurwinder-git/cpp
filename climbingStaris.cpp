#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int climb(int n);
int main()
{
    int steps = 5;
    cout << "total ways to climb: " << climb(steps);
    return 0;
}

// memorization
int solve(int level, int n, unordered_map<int, int> &memo)
{
    if (level == n)
        return 1;
    if (level > n)
        return 0;

    if (memo.find(level) != memo.end())
        return memo[level];

    int left = solve(level + 1, n, memo);
    int right = solve(level + 2, n, memo);

    memo[level] = left + right;

    return memo[level];
}

int climb(int n)
{
    unordered_map<int, int> memo;
    return solve(0, n, memo);
}

// optimal
//  int climb(int n)
//  {
//      int preTopre = 1;
//      int pre = 2;

//     for (int i = 2; i < n; i++)
//     {
//         int ans = pre + preTopre;
//         preTopre = pre;
//         pre = ans;
//     }

//     return n > 1 ? pre : 1;
// }