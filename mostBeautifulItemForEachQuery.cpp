#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries);
int main()
{
    vector<vector<int>> items({{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}});
    vector<int> queires({1, 2, 3, 4, 5, 6});

    vector<int> res = maximumBeauty(items, queires);

    for (int i : res)
        cout << i << " ";
    return 0;
}
// vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
// {
//     vector<int> output(queries.size());

//     for (int i = 0; i < queries.size(); i++)
//     {
//         int maxProfit = 0;

//         for (int j = 0; j < items.size(); j++)
//         {
//             if (queries[i] >= items[j][0])
//             {
//                 maxProfit = max(maxProfit, items[j][1]);
//             }
//         }
//         output[i] = maxProfit;
//     }
//     return output;
// }

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{
    sort(items.begin(), items.end());
    map<int, int> mp;
    int maxBeauty = INT_MIN;

    for (vector<int> item : items)
    {
        maxBeauty = max(maxBeauty, item[1]);
        mp[item[0]] = maxBeauty;
    }

    vector<int> ans(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        if (mp.find(queries[i]) != mp.end())
            ans[i] = mp[queries[i]];
        else
        {
            map<int, int>::iterator itr = mp.lower_bound(queries[i]);

            if (itr != mp.begin())
            {
                itr--;
                ans[i] = (*itr).second;
            }
            else
            {
                ans[i] = 0;
            }
        }
    }
    return ans;
}

// [[193,732],[781,962],[864,954],[749,627],[136,746],[478,548],[640,908],[210,799],[567,715],[914,388],[487,853],[533,554],[247,919],[958,150],[193,523],[176,656],[395,469],[763,821],[542,946],[701,676]]
// [885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584]