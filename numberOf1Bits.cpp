#include <iostream>

using namespace std;

class Solution
{
public:
    // int hammingWeight(uint32_t n) {

    //     int totalOnes = 0;

    //     while (n)
    //     {
    //         totalOnes += n % 2;
    //         n = n >> 1;
    //     }

    //     return totalOnes;
    // }

    // using masking
    //  int hammingWeight(uint32_t n) {

    //     uint32_t mask = 1;

    //     int i = 0;
    //     int totalOnes = 0;
    //     while (i < 32)
    //     {
    //         if((n & mask) > 0)
    //             totalOnes++;
    //         mask = mask << 1;
    //         i++;
    //     }
    //     return totalOnes;
    // }

    // optimal
    int hammingWeight(uint32_t n)
    {

        int totalOnes = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            totalOnes++;
        }

        return totalOnes;
    }
};

int main()
{

    uint32_t n = 11;
    Solution sol;
    cout << sol.hammingWeight(n);
    return 0;
}