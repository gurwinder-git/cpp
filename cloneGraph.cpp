#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    // optimal
    // unordered_map<Node *, Node *> oldVsNew;
    // Node *cloneGraph(Node *node)
    // {
    //     if (!node)
    //         return NULL;

    //     // if not mapped
    //     if (oldVsNew.find(node) == oldVsNew.end())
    //     {
    //         Node *newNode = new Node(node->val);
    //         oldVsNew[node] = newNode;

    //         for (Node *&neighbor : node->neighbors)
    //         {
    //             newNode->neighbors.push_back(cloneGraph(neighbor));
    //         }
    //     }

    //     return oldVsNew[node];
    // }

    // my brutte force
    unordered_map<Node *, bool> visited;
    unordered_map<Node *, Node *> copies;

    void markCopies(Node *node)
    {
        visited[node] = true;

        copies[node] = new Node(node->val);
        for (Node *&n : node->neighbors)
        {
            if (visited.find(n) == visited.end())
                markCopies(n);
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return node;

        markCopies(node);

        queue<Node *> q;
        q.push(node);
        visited[node] = false;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            Node *replicateOfCurrNode = copies[curr];

            for (Node *&n : curr->neighbors)
            {
                Node *replicateOfneighbor = copies[n];
                replicateOfCurrNode->neighbors.push_back(replicateOfneighbor);

                if (visited[n] == true)
                {
                    visited[n] = false;
                    q.push(n);
                }
            }
        }

        return copies[node];
    }
};

void dfs(Node *node, unordered_map<Node *, bool> &visisted)
{
    cout << node->val << "  ";
    visisted[node] = true;
    for (Node *n : node->neighbors)
    {
        if (visisted.find(n) == visisted.end())
            dfs(n, visisted);
    }
}
int main()
{
    Node *node = new Node(1);

    // 1---->2
    // |
    // \/
    //  4
    node->neighbors.push_back(new Node(2));
    node->neighbors.push_back(new Node(4));

    // 1<---->2
    // |      |
    // \/     \/
    //  4     3
    node->neighbors[0]->neighbors.push_back(node);
    node->neighbors[0]->neighbors.push_back(new Node(3));
    /* 1<---->2
    // /\     |
    // \/    \/
       4----->3*/
    node->neighbors[1]->neighbors.push_back(node);
    node->neighbors[1]->neighbors.push_back(node->neighbors[0]->neighbors[1]);

    /* 1<---->2
    // /\     /\
    // \/     \/
       4<---->3*/
    node->neighbors[0]->neighbors[1]->neighbors.push_back(node->neighbors[0]);
    node->neighbors[0]->neighbors[1]->neighbors.push_back(node->neighbors[1]);

    unordered_map<Node *, bool> visisted;
    Solution sol;

    Node *clone = sol.cloneGraph(node);
    dfs(node, visisted);
    cout << endl
         << "-----------" << endl;
    dfs(clone, visisted);

    return 0;
}