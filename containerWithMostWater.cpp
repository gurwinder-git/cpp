#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // optimal O(n)
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int i = 0;
        int j = height.size() - 1;
        int leftHeight, rightHeight, minHeight, water;

        while (i < j)
        {
            leftHeight = height[i];
            rightHeight = height[j];

            minHeight = leftHeight < rightHeight ? leftHeight : rightHeight;

            water = minHeight * (j - i);

            maxWater = water > maxWater ? water : maxWater;

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxWater;
    }

    // my brutte force n^2
    // int maxArea(vector<int> &height)
    // {
    //     int maxWater = 0;
    //     int n = height.size();

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             int left = height[i];
    //             int right = height[j];
    //             int minHeight = left <= right ? left : right;

    //             int water = minHeight * (j - i);

    //             maxWater = water > maxWater ? water : maxWater;
    //         }
    //     }

    //     return maxWater;
    // }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution sol;

    cout << sol.maxArea(height);
    return 0;
}