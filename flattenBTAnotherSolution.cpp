#include <iostream>
#include <stack>
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

    static void traverse(treeNode *treeNode)
    {
        if (treeNode == NULL)
            return;

        cout << treeNode->val;
        traverse(treeNode->left);
        traverse(treeNode->right);
    }

    static void flattenBT(treeNode *root)
    {
        if (!root)
            return;

        stack<treeNode *> heleprStack;

        while (root->left || root->right || !heleprStack.empty())
        {
            //root has left and right child both
            if (root->left && root->right)
            {
                heleprStack.push(root->right);
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
            //root has only one child left of right
            else if ((root->left && !(root->right)) || (!(root->left) && root->right))
            {
                if (root->left) //if root has left child
                {
                    root->right = root->left;
                    root->left = NULL;
                    root = root->right;
                }
                else //else it has right child
                    root = root->right;
            }
            //if root has not child
            else
            {
                root->right = heleprStack.top();
                heleprStack.pop();
                root = root->right;
            }
        }
    }
};

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(5);

    //         1
    //        / \
    //       2   5
    //      / \   \
    //     3   4   6
    root->left->left = new treeNode(3);
    root->left->right = new treeNode(4);
    root->right->right = new treeNode(6);
    // (*(*root).left).right = new treeNode();

    treeNode::flattenBT(root);
    treeNode::traverse(root);

    return 0;
}