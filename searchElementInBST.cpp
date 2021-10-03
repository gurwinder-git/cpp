#include <iostream>
using namespace std;

class treeNode
{
public:
    treeNode *left;
    int val;
    treeNode *right;

    treeNode()
    {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }

    treeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    treeNode(int val, treeNode *left, treeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

treeNode *searchBST(treeNode *root, int val);
void traverse(treeNode *nodePtr);

int main()
{

    treeNode *root = new treeNode(4);
    root->left = new treeNode(2);
    root->right = new treeNode(7);

    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);

    // (*(*root).left).right = new treeNode();

    treeNode *res = searchBST(root, 2);
    traverse(res);

    return 0;
}

void traverse(treeNode *nodePtr)
{
    if (nodePtr == NULL)
        return;

    traverse(nodePtr->left);
    cout << nodePtr->val << "  ";
    traverse(nodePtr->right);
}

treeNode *searchBST(treeNode *root, int num)
{
    while (root)
    {
        if (root->val == num)
            return root;
        else if (root->val > num)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}