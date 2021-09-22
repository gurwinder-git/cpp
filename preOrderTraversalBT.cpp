#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preOrder(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<int> res = preOrder(root);

    vector<int>::iterator it = res.begin();
    for (it; it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}

//recusive

// void traverse(TreeNode *nodePtr, vector<int> &res)
// {
//     if (nodePtr == NULL)
//         return;

//     res.push_back(nodePtr->val);
//     traverse(nodePtr->left, res);
//     traverse(nodePtr->right, res);
// }

// vector<int> preOrder(TreeNode *root)
// {
//     vector<int> res;
//     traverse(root, res);
//     return res;
// }

//iterative

vector<int> preOrder(TreeNode *root)
{
    stack<TreeNode *> helperStack;
    vector<int> res;

    while (root || !helperStack.empty())
    {
        if (root)
        {
            res.push_back(root->val);
            helperStack.push(root);
            root = root->left;
        }
        else
        {
            root = helperStack.top();
            helperStack.pop();
            root = root->right;
        }
    }

    return res;
}