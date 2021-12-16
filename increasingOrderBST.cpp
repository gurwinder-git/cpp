#include <iostream>
#include <stack>

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

TreeNode *increasingOrder(TreeNode *root);

void traverse(TreeNode *nodePtr);

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    root = increasingOrder(root);

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

void inOrderStore(TreeNode *nodePtr, stack<TreeNode *> &helperStack)
{
    if (nodePtr == NULL)
        return;

    inOrderStore(nodePtr->left, helperStack);
    helperStack.push(nodePtr);
    inOrderStore(nodePtr->right, helperStack);
}

TreeNode *increasingOrder(TreeNode *root)
{
    stack<TreeNode *> helperStack;
    inOrderStore(root, helperStack);

    TreeNode *ansRoot = NULL;
    while (!helperStack.empty())
    {
        TreeNode *top = helperStack.top();
        helperStack.pop();

        top->right = ansRoot;
        top->left = NULL;

        ansRoot = top;
    }

    return ansRoot;
}