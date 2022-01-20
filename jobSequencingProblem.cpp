#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;

    // Job(int id, int dead, int profit)
    // {
    //     this->id = id;
    //     this->dead = dead;
    //     this->profit = profit;
    // }
};

bool comp(Job a, Job b)
{
    // if (a.profit == b.profit)
    //     return a.dead > b.dead;

    return a.profit > b.profit;
}

// 4,10//3,10
class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        int maximumDeadlines = 0;
        vector<Job> sortedJobs(n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i].dead > maximumDeadlines)
            {
                maximumDeadlines = arr[i].dead;
            }
            sortedJobs[i] = arr[i];
        }

        vector<int> isOccupied(maximumDeadlines + 1, -1);

        sort(sortedJobs.begin(), sortedJobs.end(), comp);

        for (int i = 0; i < n; i++)
        {
            int deadLine = sortedJobs[i].dead;
            if (isOccupied[deadLine] == -1)
            {
                isOccupied[deadLine] = sortedJobs[i].profit;
            }
            else
            {
                deadLine--;
                while (deadLine > 0 && isOccupied[deadLine] > -1)
                {
                    deadLine--;
                }

                if (deadLine > 0)
                {
                    isOccupied[deadLine] = sortedJobs[i].profit;
                }
            }
        }

        int maxProfit = 0;
        int totalJobs = 0;
        for (int i = 1; i < isOccupied.size(); i++)
        {
            if (isOccupied[i] != -1)
            {
                totalJobs++;
                maxProfit += isOccupied[i];
            }
        }

        return {totalJobs, maxProfit};
    }
};

int main()
{

    Job arr[5];
    arr[0].id = 1;
    arr[0].dead = 4;
    arr[0].profit = 20;

    arr[1].id = 2;
    arr[1].dead = 1;
    arr[1].profit = 10;

    arr[2].id = 3;
    arr[2].dead = 1;
    arr[2].profit = 40;

    arr[3].id = 4;
    arr[3].dead = 2;
    arr[3].profit = 30;

    arr[4].id = 5;
    arr[4].dead = 3;
    arr[4].profit = 30;

    Solution sol;

    vector<int> v = sol.JobScheduling(arr, 5);

    cout << "total jobs: " << v[0] << endl;
    cout << "MAX profit: " << v[1];

    return 0;
}