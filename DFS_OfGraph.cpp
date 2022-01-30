#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> res;
    void dfs(vector<int> adj[], int vertex, vector<bool> &visited)
    {
        res.push_back(vertex);

        for (int i = 0; i < adj[vertex].size(); i++)
        {
            if (visited[adj[vertex][i]] == false)
            {
                visited[adj[vertex][i]] = true;
                dfs(adj, adj[vertex][i], visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        visited[0] = true;
        dfs(adj, 0, visited);
        return res;
    }
};

int main()
{

    vector<int> adj[5] = {
        vector<int>({1, 2}), // 0
        vector<int>({3}),    // 1
        vector<int>({4}),    // 2
        vector<int>({2}),    // 3
        vector<int>({})};    // 4
    Solution sol;

    vector<int> dfs = sol.dfsOfGraph(5, adj);

    for (int i : dfs)
    {
        cout << i << "  ";
    }

    return 0;
}
