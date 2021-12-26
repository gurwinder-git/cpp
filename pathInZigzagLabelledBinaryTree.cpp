#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int compliment(int label, int start, int end)
    {
        int diff = end - label;
        return start + diff;
    }

    vector<int> pathInZigZagTree(int label)
    {
        int start = 1, end = 1;
        vector<int> res = {label};

        while (end < label)
        {
            start = end + 1;
            end = end * 2 + 1;
        }

        while (label > 1)
        {
            int parent = this->compliment(label, start, end) / 2;

            res.push_back(parent);

            label = parent;

            start = start / 2;
            end = end / 2;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
int main()
{
    int label = 14;

    Solution sol;
    vector<int> res = sol.pathInZigZagTree(label);

    for (int i : res)
        cout << i << " ";

    return 0;
}