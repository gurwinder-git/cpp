#include <iostream>
#include <queue>
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

vector<int> inOrder(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<int> res = inOrder(root);

    vector<int>::iterator it = res.begin();
    for (it; it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}

void traverse(TreeNode *nodePtr, vector<int> &res)
{
    if (nodePtr == NULL)
        return;

    traverse(nodePtr->left, res);
    res.push_back(nodePtr->val);
    traverse(nodePtr->right, res);
}

vector<int> inOrder(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}