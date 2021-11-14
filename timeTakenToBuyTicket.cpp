#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k);

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << timeRequiredToBuy(nums, 2);

    return 0;
}

int timeRequiredToBuy(vector<int> &tickets, int k)
{

    int benefitTime = 0;
    for (int i = 0; i <= k; i++)
    {
        tickets[i]--;
        benefitTime++;
    }

    int time = 0;

    while (tickets[k] > 0)
    {
        for (int i = 0; i < tickets.size(); i++)
        {

            if (tickets[i] > 0)
            {
                time++;
                tickets[i]--;
            }
        }
    }

    return time + benefitTime;
}