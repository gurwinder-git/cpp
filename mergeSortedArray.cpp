#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int end = nums1.size() - 1;
        m--;
        n--;

        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[end] = nums1[m];
                end--;
                m--;
            }
            else
            {
                nums1[end] = nums2[n];
                end--;
                n--;
            }
        }

        while (n >= 0)
        {
            nums1[n] = nums2[n];
            n--;
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 6, 8};

    Solution sol;

    sol.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    for (int i : nums1)
    {
        cout << i << "  ";
    }

    return 0;
}