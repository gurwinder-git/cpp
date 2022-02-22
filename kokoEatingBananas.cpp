#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int minEat = 1;
        int maxEat = 1000000000;
        int midEat, myHours, ans;

        while (minEat <= maxEat)
        {
            midEat = (minEat + maxEat) / 2;
            myHours = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                myHours += ceil((piles[i] * 1.0) / midEat);
            }

            if (myHours <= h)
            {
                ans = midEat;
                maxEat = midEat - 1;
            }
            else
            {
                minEat = midEat + 1;
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    Solution sol;
    cout << sol.minEatingSpeed(piles, h);
    return 0;
}