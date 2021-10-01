#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices);
int main()
{
    vector<int> prices = {7, 1, 2, 3, 4, 6, 3};
    cout << maxProfit(prices);
    return 0;
}
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;

        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}