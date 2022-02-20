#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // optimal nlogn
    static bool comp(vector<int> &i1, vector<int> &i2)
    {
        if (i1[0] == i2[0])
        {
            return i1[1] > i2[1];
        }
        return i1[0] < i2[0];
    }
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        int remainingIntervals = intervals.size();

        int maxEnd = intervals[0][1];
        int i = 1;

        while (i < intervals.size())
        {
            if (maxEnd >= intervals[i][1])
            {
                remainingIntervals--;
            }
            else
            {
                maxEnd = max(maxEnd, intervals[i][1]);
            }
            i++;
        }

        return remainingIntervals;
    }

    //  n^2 time
    //  int removeCoveredIntervals(vector<vector<int>> &intervals)
    //  {
    //      int remainingIntervals = intervals.size();
    //      int replaceWith = 100001;

    //     for (int i = 0; i < intervals.size(); i++)
    //     {
    //         if (intervals[i][0] == replaceWith)
    //             continue;
    //         for (int j = i + 1; j < intervals.size(); j++)
    //         {
    //             if (intervals[j][0] == replaceWith)
    //             {
    //                 continue;
    //             }
    //             else if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1])
    //             {
    //                 intervals[j][0] = replaceWith;
    //                 remainingIntervals--;
    //             }
    //             else if (intervals[i][0] >= intervals[j][0] && intervals[j][1] >= intervals[i][1])
    //             {
    //                 // intervals[i][0] = replaceWith;
    //                 remainingIntervals--;
    //                 break;
    //             }
    //         }
    //     }

    //     return remainingIntervals;
    // }
};
int main()
{

    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}, {1, 2}};

    Solution sol;

    cout << sol.removeCoveredIntervals(intervals);
    return 0;
}