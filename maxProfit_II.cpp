#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices);
int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit you can take: " << maxProfit(prices);
    return 0;
}

int maxProfit(vector<int> &prices)
{
    int assumeToBuyAt = prices[0];
    int maxProfit = 0;

    // i = 1  because we are assuming that we buy stoct at prices[0]
    for (int i = 1; i < prices.size(); i++)
    {
        // if sell    -     buy       > 0 then simply add to maxprofit
        if (prices[i] - assumeToBuyAt > 0)
        {
            // addind profit to maxProfit
            maxProfit += prices[i] - assumeToBuyAt;
            // assume to buy that selling stock at same day.
            assumeToBuyAt = prices[i];
        }
        else // if sell - buy (profit) 0 or less than 0, then find the min between buy and sell
            assumeToBuyAt = prices[i];
    }
    return maxProfit;
}