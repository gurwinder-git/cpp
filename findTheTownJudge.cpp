#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> degres(n + 1, 0);

        for (int i = 0; i < trust.size(); i++)
        {
            int out = trust[i][0];
            int in = trust[i][1];
            degres[out] = degres[out] - 1;
            degres[in] = degres[in] + 1;
        }

        for (int i = 1; i < degres.size(); i++)
        {
            if (degres[i] == n - 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    Solution sol;
    int totalPersons = 3;

    cout << "judge: " << sol.findJudge(totalPersons, trust);
    return 0;
}