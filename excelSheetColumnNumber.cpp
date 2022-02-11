#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        long pow = 1;
        int ans = 0;

        for (int i = columnTitle.size() - 1; i >= 0; i--)
        {
            ans = ans + ((columnTitle[i] - 'A' + 1) * pow);
            pow = pow * 26;
        }

        return ans;
        
    }
};

int main()
{
    Solution sol;
    cout<<sol.titleToNumber("AB");
    return 0;
}