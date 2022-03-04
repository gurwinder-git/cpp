#include <iostream>
#include <vector>

using namespace std;
class Solution
{

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int ans = -1;
        int l = 0;
        int h = arr.size() - 1;

        while (l < h)
        {
            int mid = (l + h) / 2;

            if (arr[mid] > arr[mid + 1]) // if mid larger
            {
                h = mid;
                ans = mid;
            }
            else // if mid smaller
            {
                l = mid + 1;
                ans = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 3, 2, 1};
    Solution sol;

    cout << sol.peakIndexInMountainArray(arr);
    return 0;
}