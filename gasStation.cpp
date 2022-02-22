#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // optimal
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int diff = 0;
        int curruntGas = 0;
        int ans = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            diff += gas[i] - cost[i];

            curruntGas += gas[i];
            curruntGas -= cost[i];

            if (curruntGas < 0)
            {
                curruntGas = 0;
                ans = i + 1;
            }
        }
        if (diff < 0)
            return -1;
        return ans;
    }
    // TLE
    // int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    // {
    //     int j, counter, curruntGas;
    //     int n = gas.size();

    //     for (int i = 0; i < n; i++)
    //     {
    //         j = i;
    //         counter = 0;
    //         curruntGas = 0;

    //         while (counter < n)
    //         {
    //             curruntGas += gas[j];
    //             curruntGas -= cost[j];
    //             if (curruntGas < 0)
    //                 break;
    //             counter++;

    //             j = (j + 1) % n;
    //         }
    //         if (counter == n)
    //             return i;
    //     }

    //     return -1;
    // }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost);
    return 0;
}
