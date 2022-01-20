#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    double av = a.value * 1.0;
    double v1 = av / a.weight;

    double bv = b.value * 1.0;
    double v2 = bv / b.weight;
    return v1 > v2;
}
// value/ weight
//  60/10 = 6
//  100/20 = 5
class Solution
{
public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        if (n == 0)
            return 0;
        cout << endl;
        sort(arr, arr + n, comp);

        // for (int i = 0; i < n; i++)
        //     cout << arr[i].value << "  " << arr[i].weight << endl;

        double profit = 0;
        for (int i = 0; i < n; i++)
        {
            int weightOfItem = arr[i].weight;

            if (weightOfItem <= W)
            {
                double v = arr[i].value * 1.0;
                profit = (profit + v) * 1.0;
                W -= weightOfItem;
            }
            else
            {
                double v = arr[i].value * 1.0;
                double perUnitValue = v / weightOfItem;
                profit = profit + (perUnitValue * W);
                break;
            }
        }

        return profit;
    }
};

int main()
{
    Item arr[3];

    arr[0].value = 60;
    arr[0].weight = 10;

    arr[1].value = 100;
    arr[1].weight = 20;

    arr[2].value = 120;
    arr[2].weight = 30;

    Solution sol;

    cout << "Maximum Profit: " << sol.fractionalKnapsack(50, arr, 3);
    return 0;
}