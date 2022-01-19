#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
    // my solution O(nlogn) time and O(2n) space
    int findPlatform(int arr[], int dep[], int n)
    {
        if (n == 0)
            return 0;

        multimap<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 1;
        for (int i = 0; i < n; i++)
            mp.insert({arr[i], dep[i]});

        multimap<int, int>::iterator itr = mp.begin();

        minHeap.push(itr->second);

        itr++;

        for (; itr != mp.end(); itr++)
        {
            while (!minHeap.empty() && minHeap.top() < itr->first)
            {
                minHeap.pop();
            }
            minHeap.push(itr->second);

            if (minHeap.size() > ans)
            {
                ans = minHeap.size();
            }
        }

        return ans;
    }
};
int main()
{

    int arrival[] = {900, 940, 950, 1100, 1500, 1800};
    int departure[] = {910, 1200, 1120, 1130, 1900, 2000};

    Solution sol;

    cout << sol.findPlatform(arrival, departure, 6);

    return 0;
}