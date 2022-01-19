#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        multimap<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp.insert({end[i], start[i]});
        }

        int ans = 1;
        multimap<int, int>::iterator itr = mp.begin();
        int previousEndTime = itr->first;

        itr++;
        for (; itr != mp.end(); itr++)
        {
            if (itr->second > previousEndTime)
            {
                ans++;
                previousEndTime = itr->first;
            }
        }

        return ans;
    }
};

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5, 6};
    int end[] = {2, 4, 6, 7, 9, 9, 9};

    Solution sol;

    cout << sol.maxMeetings(start, end, 7);

    return 0;
}