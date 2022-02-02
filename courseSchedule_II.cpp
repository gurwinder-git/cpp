#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    void topoSort_(vector<vector<int>> &adj, int src, vector<bool> &visited)
    {
        visited[src] = true;

        for (int i = 0; i < adj[src].size(); i++)
        {
            if (visited[adj[src][i]] == false)
                topoSort_(adj, adj[src][i], visited);
        }
        ans.push_back(src);
    }
    bool findCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &explored)
    {
        visited[src] = true;

        for (int i : adj[src])
        {
            if (visited[i] == false)
            {

                if (findCycle(i, adj, visited, explored))
                    return true;
            }
            else if (explored[i] == false)
                return true;
        }

        explored[src] = true;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int source = prerequisites[i][0];
            int dest = prerequisites[i][1];
            adj[source].push_back(dest);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> explored(numCourses, false);

        for (int i = 0; i < numCourses; i++)
            if (visited[i] == false)
                if (findCycle(i, adj, visited, explored))
                    return {};

        for (int i = 0; i < numCourses; i++)
            visited[i] = false;

        for (int i = 0; i < numCourses; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                topoSort_(adj, i, visited);
            }

        return ans;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {0, 3}, {4, 1}};
    Solution sol;

    vector<int> order = sol.findOrder(4, prerequisites);

    for (int i : order)
        cout << i << "  ";

    return 0;
}