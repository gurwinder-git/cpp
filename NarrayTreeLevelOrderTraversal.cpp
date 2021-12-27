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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<Node *> q({root});

        while (!q.empty())
        {
            int sizeOfq = q.size();
            vector<int> row;

            while (sizeOfq--)
            {
                Node *currNode = q.front();
                q.pop();

                row.push_back(currNode->val);

                for (int i = 0; i < currNode->children.size(); i++)
                {
                    q.push(currNode->children[i]);
                }
            }
            ans.push_back(row);
        }

        return ans;
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
    vector<vector<int>> res = sol.levelOrder(root);

    for (auto v : res)
    {
        for (int i : v)
        {
            cout << i << "  ";
        }
        cout << endl;
    }

    return 0;
}