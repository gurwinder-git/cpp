#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool findCycle(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &explored)
    {
        visited[src] = true;

        for (int i : adj[src])
        {
            if (visited[i] == false)
            {
                if (findCycle(i, adj, visited, explored))
                {
                    return true;
                }
            }
            else if (explored[i] == false)
            {
                return true;
            }
        }

        explored[src] = true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> *adj = new vector<int>[numCourses];

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int source = prerequisites[i][0];
            int dest = prerequisites[i][1];

            adj[source].push_back(dest);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> explored(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == false)
            {
                if (findCycle(i, adj, visited, explored))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {0, 3}, {4, 1}};
    Solution sol;

    cout << sol.canFinish(4, prerequisites);
    return 0;
}