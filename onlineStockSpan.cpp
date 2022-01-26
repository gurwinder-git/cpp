#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// O(1) most of the time
class StockSpanner
{
public:
    stack<pair<int, int>> stk;
    int currIndex;

    StockSpanner()
    {
        currIndex = -1;
    }

    int next(int price)
    {
        currIndex++;
        // stk.top().second = value
        // stk.top().first = index
        while (!stk.empty() && stk.top().second <= price)
        {
            stk.pop();
        }

        int ans;

        if (stk.empty())
            ans = currIndex + 1;
        else
            ans = currIndex - stk.top().first;

        stk.push({currIndex, price});

        return ans;
    }
};

int main()
{
    StockSpanner stockSpanner;
    // [100], [80], [60], [70], [60], [75], [85]
    cout << stockSpanner.next(100) << "  ";
    cout << stockSpanner.next(80) << "  ";
    cout << stockSpanner.next(60) << "  ";
    cout << stockSpanner.next(70) << "  ";
    cout << stockSpanner.next(60) << "  ";
    cout << stockSpanner.next(75) << "  ";
    cout << stockSpanner.next(85) << "  ";
    return 0;
}