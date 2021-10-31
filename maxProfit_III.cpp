#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices);
int main()
{
    vector<int> prices = {21, 2, 3, 4, 3, 2, 11};
    cout << "max profit with only two transetions is: " << maxProfit(prices);
    return 0;
}

int maxProfit(vector<int> &prices)
{
    int length = prices.size();
    vector<int> bestBuyPointToLeft(length);
    bestBuyPointToLeft[0] = 0;
    int minPrice = prices[0];

    for (int i = 1; i < length; i++)
    {
        minPrice = min(minPrice, prices[i]);
        int currProfit = prices[i] - minPrice;

        if (currProfit > bestBuyPointToLeft[i - 1])
            bestBuyPointToLeft[i] = currProfit;
        else
            bestBuyPointToLeft[i] = bestBuyPointToLeft[i - 1];
    }

    vector<int> bestSellPointToRight(length);
    bestSellPointToRight[length - 1] = 0;
    int maxPrice = prices[length - 1];

    for (int i = length - 2; i > 0; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        int currProfit = maxPrice - prices[i];

        if (currProfit > bestSellPointToRight[i + 1])
            bestSellPointToRight[i] = currProfit;
        else
            bestSellPointToRight[i] = bestSellPointToRight[i + 1];
    }

    int res = 0;
    for (int i = 0; i < length; i++)
    {
        res = res < bestBuyPointToLeft[i] + bestSellPointToRight[i] ? bestBuyPointToLeft[i] + bestSellPointToRight[i] : res;
    }

    return res;
}