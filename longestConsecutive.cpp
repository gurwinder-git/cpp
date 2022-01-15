#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int> &nums);
int main()
{
    vector<int> nums = {5, 4, 2, 1};
    cout << longestConsecutive(nums);
    return 0;
}

// brute force O(nlogn)
//  int longestConsecutive(vector<int> &nums)
//  {
//      if (nums.size() == 0)
//          return 0;

//     sort(nums.begin(), nums.end());

//     int maxlenght = 1;
//     int curruntMaxLenght = 1;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] == nums[i - 1])
//             continue;

//         if ((nums[i] - 1) == nums[i - 1])
//             curruntMaxLenght++;
//         else
//         {
//             maxlenght = max(maxlenght, curruntMaxLenght);
//             curruntMaxLenght = 1;
//         }
//     }
//     return max(maxlenght, curruntMaxLenght);
// }

// optimal O(n)
int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, bool> helperMap;

    for (int num : nums)
        helperMap.insert({num, true});

    for (int num : nums)
    {
        if (helperMap.find(num - 1) != helperMap.end())
            helperMap[num] = false;
    }

    int ans = 0;

    for (pair<int, bool> p : helperMap)
    {
        if (p.second == true)
        {
            int length = 1;
            int consecutive = p.first;

            while (helperMap.find(consecutive + length) != helperMap.end())
                length++;

            ans = max(ans, length);
        }
    }

    return ans;
}