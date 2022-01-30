#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int totalVertex, vector<int> adj[])
    {
        queue<int> q;
        vector<int> bfs;
        vector<bool> visited(totalVertex, false);
        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int currVertex = q.front();
            q.pop();

            bfs.push_back(currVertex);

            for (int i = 0; i < adj[currVertex].size(); i++)
            {
                if (visited[adj[currVertex].at(i)] == false)
                {
                    q.push(adj[currVertex].at(i));
                    visited[adj[currVertex].at(i)] = true;
                }
            }
        }
        return bfs;
    }
};

int main()
{

    vector<int> adj[5] = {
        vector<int>({1, 2, 3}), // 0
        vector<int>({}),        // 1
        vector<int>({4}),       // 2
        vector<int>({}),        // 3
        vector<int>({})};       // 4
    Solution sol;

    vector<int> bfs = sol.bfsOfGraph(5, adj);

    for (int i : bfs)
    {
        cout << i << "  ";
    }

    return 0;
}
