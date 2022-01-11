#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    double solve(double x, int n)
    {
        if (n == 1)
        {
            return x;
        }
        if (n == 0)
        {
            return 1;
        }
        double ans = solve(x, n / 2);
        if (n % 2 == 0)
        {
            return ans * ans;
        }
        else
        {
            return ans * ans * x;
        }
    }
    double myPow(double x, int n)
    {
        bool isNagtive = n < 0 ? true : false;

        double ans = solve(x, abs(n));

        if (isNagtive)
        {
            return 1 / ans;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.myPow(2, -2);
    return 0;
}