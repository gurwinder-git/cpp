#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> res;

    void solve(Node *root)
    {
        this->res.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++)
            solve(root->children[i]);
    }

    vector<int> preorder(Node *root)
    {
        if (!root)
            return this->res;
        solve(root);
        return this->res;
    }
};

int main()
{

    Node *root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution sol;
    vector<int> res = sol.preorder(root);

    for (int i : res)
        cout << i << "  ";

    return 0;
}