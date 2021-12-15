#include <iostream>
#include <string>
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

TreeNode *invertBT(TreeNode *root);

void traverse(TreeNode *nodePtr);

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root = invertBT(root);

    traverse(root);

    return 0;
}

void traverse(TreeNode *nodePtr)
{
    if (nodePtr == NULL)
        return;

    traverse(nodePtr->left);
    cout << nodePtr->val << " ";
    traverse(nodePtr->right);
}

void solve(TreeNode *currRoot)
{
    if (!currRoot)
        return;

    solve(currRoot->left);
    solve(currRoot->right);

    TreeNode *temp;

    temp = currRoot->left;
    currRoot->left = currRoot->right;
    currRoot->right = temp;
}

TreeNode *invertBT(TreeNode *root)
{
    solve(root);
    return root;
}