class Solution
{
public:
    stack<int> stk;
    void topoSort(vector<int> adj[], int src, vector<bool> &visited)
    {
        visited[src] = true;

        for (int i = 0; i < adj[src].size(); i++)
        {
            if (visited[adj[src][i]] == false)
            {
                topoSort(adj, adj[src][i], visited);
            }
        }

        stk.push(src);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<bool> visited(V, false);

        for (int i; i < V; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
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
