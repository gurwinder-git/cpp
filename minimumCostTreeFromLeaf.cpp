#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int minCostTree(vector<int> &arr);
int main()
{

    vector<int> arr = {2, 3, 5, 6, 3, 2};

    cout << "min cost tree: " << minCostTree(arr);
    return 0;
}

pair<int, int> solve(vector<int> &arr, int start, int end)
{
    if (start == end)
        return pair<int, int>(0, arr[start]);

    int minProduct = INT_MAX;
    int maxLeaf = INT_MIN;

    for (int i = start; i < end; i++)
    {
        pair<int, int> left = solve(arr, start, i);
        pair<int, int> right = solve(arr, i + 1, end);

        minProduct = min(minProduct, left.first + right.first + left.second * right.second); // first == product
        maxLeaf = max(left.second, right.second);
    }

    return {minProduct, maxLeaf};
}
int minCostTree(vector<int> &arr)
{
    return solve(arr, 0, arr.size() - 1).first;
}