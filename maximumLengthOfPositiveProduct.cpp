#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLenght(vector<int> &nums);
int main()
{
    vector<int> nums = {2, 3, -5, 3, 0, -2, 0, -3, -3, 2};
    cout << "max lenght: " << maxLenght(nums);
    return 0;
}
int maxLenght(vector<int> &nums)
{
    int ans = 0;
    int indexOfFirstNagtiveNum = -1;

    int startOfSubArray = 0;

    int product = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        product *= nums[i];

        if (product > 0)
        {
            ans = max(ans, i - startOfSubArray + 1);
        }
        else if (product < 0)
        {
            if (indexOfFirstNagtiveNum == -1)
            {
                indexOfFirstNagtiveNum = i;
            }
            else
            {
                ans = max(ans, i - indexOfFirstNagtiveNum);
            }
        }
        else
        {
            indexOfFirstNagtiveNum = -1;
            startOfSubArray = i + 1;
            product = 1;
        }
    }

    return ans;
}