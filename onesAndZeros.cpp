#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int maxSubset(vector<string> &strs, int m, int n);
int main()
{
    vector<string> strs({"11", "11", "0", "0", "10", "1", "1", "0", "11", "1", "0", "111", "11111000", "0", "11", "000", "1", "1", "0", "00", "1", "101", "001", "000", "0", "00", "0011", "0", "10000"});
    cout << "Maximum subset: " << maxSubset(strs, 5, 3);
    return 0;
}

// using recursion
// int helper(vector<pair<int, int>> &pairOf01, int m, int n, int i)
// {
//     if (i >= pairOf01.size())
//         return 0;

//     int includeed = 0;
//     int excludeed = 0;

//     excludeed = helper(pairOf01, m, n, i + 1);

//     if (m >= pairOf01[i].first && n >= pairOf01[i].second)
//     {
//         includeed = 1 + helper(pairOf01, m - pairOf01[i].first, n - pairOf01[i].second, i + 1);
//     }

//     return max(includeed, excludeed);
// }

// int maxSubset(vector<string> &strs, int m, int n)
// {
//     vector<pair<int, int>> pairOf01;

//     for (int y = 0; y < strs.size(); y++)
//     {
//         pair<int, int> curr(0, 0);
//         for (int x = 0; x < strs[y].length(); x++)
//         {
//             if (strs[y][x] == '0')
//                 curr.first++;
//             else
//                 curr.second++;
//         }
//         pairOf01.push_back(curr);
//     }

//     return helper(pairOf01, m, n, 0);
// }
