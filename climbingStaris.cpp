#include <iostream>
#include <vector>
using namespace std;

int climb(int n);
int main()
{
    int steps = 5;

    cout << "total ways to climb: " << climb(steps);
    return 0;
}

int climb(int n)
{
    int preTopre = 1;
    int pre = 2;

    for (int i = 2; i < n; i++)
    {
        int ans = pre + preTopre;
        preTopre = pre;
        pre = ans;
    }

    return n > 1 ? pre : 1;
}