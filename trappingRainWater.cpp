#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // O(n) time ans O(1) space
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        int ans = 0;
        int maxLeft = 0;
        int maxRight = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            if (height[left] < height[right])
            {

                if (height[left] < maxLeft) // mean this value (height[left]) is smaller than its left and right bar
                {
                    ans += maxLeft - height[left];
                }
                else
                {
                    maxLeft = height[left];
                }
                left++;
            }
            else
            {
                if (height[right] < maxRight) // means height[right] < height[left] && height[right] < maxRight
                {
                    ans += maxRight - height[right];
                }
                else
                {
                    maxRight = height[right];
                }
                right--;
            }
        }
        return ans;
    }

    // O(n) time O(n) space
    // int trap(vector<int> &height)
    // {
    //     if (height.size() == 0)
    //         return 0;
    //     vector<int> maxLeft(height.size());
    //     vector<int> maxRight(height.size());

    //     maxLeft[0] = height[0];
    //     maxRight[height.size() - 1] = height[height.size() - 1];
    //     int ans = 0;

    //     // for maxLeft
    //     for (int i = 1; i < height.size(); i++)
    //         maxLeft[i] = max(maxLeft[i - 1], height[i]);

    //     // maxRight
    //     for (int i = height.size() - 2; i >= 0; i--)
    //         maxRight[i] = max(maxRight[i + 1], height[i]);

    //     // calculate answer
    //     for (int i = 0; i < height.size(); i++)
    //     {
    //         ans += (min(maxLeft[i], maxRight[i]) - height[i]);
    //     }

    //     return ans;
    // }

    // O(n^2) time O(1) space
    //  int trap(vector<int> &height)
    //  {
    //      int ans = 0;

    //     for (int i = 0; i < height.size(); i++)
    //     {
    //         int leftMax = 0;
    //         int rightMax = 0;

    //         for (int j = 0; j < i; j++)
    //         {
    //             if (height[j] > height[i])
    //             {
    //                 leftMax = max(leftMax, height[j]);
    //             }
    //         }

    //         for (int k = i + 1; k < height.size(); k++)
    //         {
    //             if (height[k] > height[i])
    //             {
    //                 rightMax = max(rightMax, height[k]);
    //             }
    //         }

    //         int minWater = min(leftMax, rightMax);

    //         if (minWater > 0)
    //         {
    //             ans += minWater;
    //             ans -= height[i];
    //         }
    //     }
    //     return ans;
    // }
};

int main()
{
    vector<int> height({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    Solution sol;

    cout << "max water: "
         << sol.trap(height);
    return 0;
}