#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (target >= letters.back())
            return letters.front();
        char ans;

        int l = 0, h = letters.size() - 1;

        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (letters[mid] <= target)
            {
                l = mid + 1;
            }
            else if (letters[mid] > target)
            {
                ans = letters[mid];
                h = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'g'};
    Solution sol;

    cout << sol.nextGreatestLetter(letters, 'f');
    return 0;
}