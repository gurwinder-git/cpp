#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &graph, int nodeVal, vector<int> &path, int src)
    {
        path.push_back(nodeVal);

        if (path.back() == src)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        for (int i = 0; i < graph[nodeVal].size(); i++)
        {
            dfs(graph, graph[nodeVal][i], path, src);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> path;
        dfs(graph, 0, path, graph.size() - 1);

        return res;
    }
};

int main()
{
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    Solution sol;

    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);
    cout << "[";
    for (int i = 0; i < paths.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << "  ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}