#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

vector<int> postOrder(Node *root);
int main()
{

    Node *root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    vector<int> res = postOrder(root);

    for (int i : res)
        cout << i << " ";
    return 0;
}

void solve(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        solve(root->children[i], res);
    }

    res.push_back(root->val);
}
vector<int> postOrder(Node *root)
{
    vector<int> res;
    solve(root, res);
    return res;
}