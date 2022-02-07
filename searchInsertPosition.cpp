#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0;
        int r= nums.size() - 1;
        int mid;

        while (l < r)
        {
             mid = (l+r)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else
                r = mid - 1;
        }
        //l == r true
        if(nums[l] >= target)
            return l;
        return l + 1;
    }
};

int main()
{
    vector<int> nums = {1,3,5,7};
    Solution sol;
    cout<<sol.searchInsert(nums, 8);
    return 0;
}