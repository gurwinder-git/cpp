#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int findKthLargest(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {-1, 2, 0};
    cout << findKthLargest(nums, 2);
    return 0;
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++)
    //     maxHeap.push(nums[i]);

    while (k > 1)
    {
        maxHeap.pop();
        k--;
    }

    return maxHeap.top();
}