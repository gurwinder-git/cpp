#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    stack<int> stk;

    void topoSort_(vector<int> adj[], int src, vector<bool> &visited)
    {
        visited[src] = true;

        for (int i = 0; i < adj[src].size(); i++)
        {
            if (visited[adj[src][i]] == false)
            {
                topoSort_(adj, adj[src][i], visited);
            }
        }
        stk.push(src);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                topoSort_(adj, i, visited);
            }
        }

        vector<int> res(stk.size());
        int i = 0;
        while (!stk.empty())
        {
            res[i] = stk.top();
            stk.pop();
            i++;
        }

        return res;
    }
};

int main()
{
    vector<int> adj[6] = {
        vector<int>({1, 2}), // 0
        vector<int>({4}),    // 1
        vector<int>({3}),    // 2
        vector<int>({1}),    // 3
        vector<int>({5}),    // 4
        vector<int>({})      // 5
    };

    Solution sol;

    vector<int> res = sol.topoSort(6, adj);

    for (int i : res)
        cout << i << "  ";

    return 0;
}
