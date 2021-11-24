#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool hasDublicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int num : nums)
    {
        mp[num]++;
        if (mp[num] > 1)
            return true;
    }

    return false;
}
int main()
{
    vector<int> nums = {24, 4, 6, 4, 4, 4, 4};
    cout << hasDublicate(nums);
    return 0;
}