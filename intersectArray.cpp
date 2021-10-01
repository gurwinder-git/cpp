#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2);
int main()
{
    vector<int> nums1 = {1, 2, 2, 2, 3};
    vector<int> nums2 = {2, 2};
    vector<int> res = intersect(nums1, nums2);
    cout << "[ ";
    for (int num : res)
        cout << num << " ";
    cout << "]";
    return 0;
}
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> freqOfNums;
    vector<int> res;

    for (int num : nums1)
        freqOfNums[num] = freqOfNums[num] + 1;

    for (int num : nums2)
    {
        if (freqOfNums[num] > 0)
        {
            res.push_back(num);
            freqOfNums[num] = freqOfNums[num] - 1;
        }
    }
    return res;
}