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

    static void predecessor(treeNode *root, treeNode *&pre, treeNode *&suc, int key)
    {
        //find the element
        pre = new treeNode(-1);
        suc = new treeNode(-1);
        while (root)
        {
            if (root->val == key)
                break;
            else if (root->val > key)
            {
                suc = root;
                root = root->left;
            }
            else
            {
                pre = root;
                root = root->right;
            }
        }

        treeNode *tempRoot = root->left;
        while (tempRoot)
        {
            pre = tempRoot;
            tempRoot = tempRoot->right;
        }

        tempRoot = root->right;
        while (tempRoot)
        {
            suc = tempRoot;
            tempRoot = tempRoot->left;
        }
    }
};

int main()
{
    treeNode *root = new treeNode(4);
    root->left = new treeNode(2);
    root->right = new treeNode(7);

    //         4
    //        / \
    //       2   7
    //      / \
    //     1   3
    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);
    // (*(*root).left).right = new treeNode();

    treeNode *pre;
    treeNode *suc;

    treeNode::predecessor(root, pre, suc, 7);
    cout << "predecessor: " << pre->val << endl;
    cout << "successor: " << suc->val;

    return 0;
}