#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxOperations(vector<int> &nums, int k);
int main()
{
    vector<int> nums = {3, 1, 3, 4, 3};
    cout << maxOperations(nums, 6);
    return 0;
}
int maxOperations(vector<int> &nums, int k)
{
    int maxPairs = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0, j = nums.size() - 1; i < j;)
    {
        int sum = nums[i] + nums[j];
        if (sum == k)
        {
            maxPairs++;
            i++;
            j--;
        }
        else if (sum > k)
            j--;
        else
            i++;
    }
    return maxPairs;
}