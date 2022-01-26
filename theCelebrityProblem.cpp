#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> stk;
        int i = 0;
        while (i < n)
        {
            stk.push(i);
            i++;
        }

        while (stk.size() > 1)
        {
            int y = stk.top();
            stk.pop();
            int x = stk.top();
            stk.pop();

            // if y knows x then y not celebrity
            if (M[y][x] == 1)
                stk.push(x);
            else
                stk.push(y);
        }

        int pot = stk.top();

        for (int i = 0; i < n; i++)
        {
            if (i != pot)
            {
                if (M[pot][i] == 1 || M[i][pot] == 0)
                {
                    return -1;
                }
            }
        }

        return pot;
    }
};

int main()
{
    vector<vector<int>> knows = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0}};

    Solution sol;
    cout << sol.celebrity(knows, 5);
    return 0;
}
