#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<Node *> q({root});

        while (!q.empty())
        {
            int qSize = q.size();
            int firstElementOfRow = q.front()->val;
            res.push_back(firstElementOfRow);

            while (qSize--)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return res;
    }
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution sol;

    vector<int> res = sol.leftView(root);

    for (int i : res)
        cout << i << " ";

    return 0;
}
