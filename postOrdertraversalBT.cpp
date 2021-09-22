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

vector<int> postOrder(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<int> res = postOrder(root);

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

//     traverse(nodePtr->left, res);
//     traverse(nodePtr->right, res);
//     res.push_back(nodePtr->val);
// }

// vector<int> postOrder(TreeNode *root)
// {
//     vector<int> res;
//     traverse(root, res);
//     return res;
// }

//iterative

vector<int> postOrder(TreeNode *root)
{
    stack<TreeNode *> helperStack({root});
    vector<int> res;

    while (helperStack.size())
    {
        root = helperStack.top();

        if (!root)
        {
            helperStack.pop();
            res.push_back(helperStack.top()->val);
            helperStack.pop();
            continue;
        }

        helperStack.push(NULL);
        if (root->right)
            helperStack.push(root->right);
        if (root->left)
            helperStack.push(root->left);
    }

    return res;
}