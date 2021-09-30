#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals);
int main()
{
    vector<vector<int>> intervals = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};

    merge(intervals);
    vector<vector<int>>::iterator itr = intervals.begin();

    for (itr; itr != intervals.end(); itr++)
    {
        vector<int>::iterator itrOfIntervals = (*itr).begin();
        for (itrOfIntervals; itrOfIntervals != (*itr).end(); itrOfIntervals++)
        {
            cout << *itrOfIntervals << " ";
        }
        cout << "   ";
    }
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res = {intervals[0]};
    auto itr = intervals.begin() + 1;

    for (; itr != intervals.end(); itr++)
    {
        if (res.back()[1] >= (*itr)[0])
            res.back()[1] = max(res.back()[1], (*itr)[1]);
        else
            res.push_back(*itr);
    }
    return res;
}