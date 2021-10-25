#include <iostream>

using namespace std;

long long int countWays(int n, int k);

int main()
{
    cout << countWays(4, 3);

    return 0;
}
long long int countWays(int n, int k)
{
    if (n == 1)
        return k;

    long long mod = 1e9 + 7;

    long long same = k * 1;
    long long diff = k * (k - 1);
    long long total = same + diff;

    for (int i = 3; i <= n; i++)
    {
        same = diff;
        diff = (total * (k - 1)) % mod;
        total = (same + diff) % mod;
    }
    return total;
}