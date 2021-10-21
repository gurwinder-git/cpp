#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int findLongestChain(vector<vector<int>> chain);

int main()
{

    vector<vector<int>> chain = {{1, 2}, {1, 2}, {3, 4}, {5, 6}};

    cout << findLongestChain(chain);
    return 0;
}

// greedy approach
bool compare(vector<int> first, vector<int> second)
{
    return (first[1] < second[1]);
}
int findLongestChain(vector<vector<int>> chain)
{

    sort(chain.begin(), chain.end(), compare);
    int max = 1;

    // cout << " {";
    // for (auto v : chain)
    // {
    //     cout << " {";
    //     for (auto i : v)
    //     {
    //         cout << i << " ,";
    //     }
    //     cout << "}";
    // }
    // cout << "}";

    for (int i = 0; i < chain.size() - 1; i++)
    {
        if (chain[i][1] < chain[i + 1][0])
            max++;
        else
        {
            int j = i + 2;
            for (; j < chain.size(); j++)
            {
                if (chain[i][1] < chain[j][0])
                {
                    max++;
                    break;
                }
            }
            i = j - 2;
        }
    }
    return max;
}

// Dynamic programming solution

// int findLongestChain(vector<vector<int>> chain)
// {
//     sort(chain.begin(), chain.end());
//     vector<short int> dp(chain.size(), 1);

//     for (int i = 0; i < chain.size() - 1; i++)
//         for (int j = i + 1; j < chain.size(); j++)
//             if (chain[i][1] < chain[j][0] && dp[i] + 1 > dp[j])
//                 dp[j] = dp[i] + 1;

//     return dp.back();
// }