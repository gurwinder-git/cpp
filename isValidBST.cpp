#include <iostream>
#include <stack>
#include <climits>
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

    static bool isValidBST(treeNode *root)
    {
        stack<treeNode *> helperStack;
        treeNode *previous = NULL;

        while (!helperStack.empty() || root)
        {
            while (root)
            {
                helperStack.push(root);
                root = root->left;
            }

            root = helperStack.top();
            helperStack.pop();

            if (previous && previous->val >= root->val)
                return false;

            previous = root;
            root = root->right;
        }
        return true;
    }
};

int main()
{
    treeNode *root = new treeNode(4);
    root->left = new treeNode(2);
    root->right = new treeNode(1);

    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);
    // (*(*root).left).right = new treeNode();
    //         4
    //        / \
    //       2   1
    //      / \
    //     1   3

    cout << (treeNode::isValidBST(root) ? "true" : "false");
    return 0;
}