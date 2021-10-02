#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> majorityElements(vector<int> &nums);
int main()
{
    vector<int> nums = {1, 3};
    nums = majorityElements(nums);
    for (int num : nums)
        cout << num << "  ";

    return 0;
}
vector<int> majorityElements(vector<int> &nums)
{
    unordered_map<int, int> frequencyOfElements;
    vector<int> res;

    int k = nums.size() / 3;

    for (int num : nums)
        frequencyOfElements[num]++;

    for (pair<int, int> obj : frequencyOfElements)
    {
        if (obj.second > k)
            res.push_back(obj.first);
    }

    return res;
}