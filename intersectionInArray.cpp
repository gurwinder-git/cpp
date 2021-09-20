#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2);

int main()
{
    vector<int> nums1 = {-1, 2, 0, 0};
    vector<int> nums2 = {3, 2, 2};
    auto intersected = intersection(nums1, nums2);
    for (int num : intersected)
    {
        cout << num << " ";
    }
    return 0;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;

    vector<int>::iterator it;
    for (int num : nums1)
    {
        it = find(nums2.begin(), nums2.end(), num);
        if (it != nums2.end())
        {
            it = find(result.begin(), result.end(), num);
            if (it == result.end())
                result.push_back(num);
        }
    }
    return result;
}
