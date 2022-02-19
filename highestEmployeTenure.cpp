#include <iostream>
#include <vector>

using namespace std;

class EmployeeNode
{
public:
    int value;
    vector<EmployeeNode *> subEmployeeNode;
    EmployeeNode(int tenure)
    {
        value = tenure;
    }
};

class Solution
{
public:
    // brutte force
    pair<int, int> solve(EmployeeNode *node, float &maxAvg, EmployeeNode *&maxTenure)
    {
        if (node->subEmployeeNode.size() <= 0)
            return {node->value, 1};

        pair<int, int> res({0, 0});

        for (int i = 0; i < node->subEmployeeNode.size(); i++)
        {
            pair<int, int> p = solve(node->subEmployeeNode[i], maxAvg, maxTenure);
            res.first += p.first;
            res.second += p.second;
        }

        // for this node
        res.first += node->value;
        res.second += 1;

        float currAvg = res.first / res.second;

        if (currAvg >= maxAvg)
        {
            maxAvg = currAvg;
            maxTenure = node;
        }
        return res;
    }
    EmployeeNode *maxTenureTeam(EmployeeNode *node)
    {
        float maxAvg = 0;
        EmployeeNode *maxTenure = NULL;

        solve(node, maxAvg, maxTenure);
        return maxTenure;
    }
};

int main()
{

    EmployeeNode *root = new EmployeeNode(20);
    root->subEmployeeNode.push_back(new EmployeeNode(12));
    root->subEmployeeNode.push_back(new EmployeeNode(18));

    root->subEmployeeNode[0]->subEmployeeNode.push_back(new EmployeeNode(11));
    root->subEmployeeNode[0]->subEmployeeNode.push_back(new EmployeeNode(2));
    root->subEmployeeNode[0]->subEmployeeNode.push_back(new EmployeeNode(3));

    root->subEmployeeNode[1]->subEmployeeNode.push_back(new EmployeeNode(15));
    root->subEmployeeNode[1]->subEmployeeNode.push_back(new EmployeeNode(8));

    Solution sol;
    cout << sol.maxTenureTeam(root)->value;
    return 0;
}
