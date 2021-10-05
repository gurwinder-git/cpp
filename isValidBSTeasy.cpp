#include <iostream>
#include <vector>
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

    static void inOrder(treeNode *root, vector<int> &inOrderArr)
    {
        if (!root)
            return;
        inOrder(root->left, inOrderArr);
        inOrderArr.push_back(root->val);
        inOrder(root->right, inOrderArr);
    }

    static bool isValidBST(treeNode *root)
    {
        vector<int> inOrderArr;
        inOrder(root, inOrderArr);

        for (int i = 1; i < inOrderArr.size(); i++)
        {
            if (inOrderArr[i - 1] >= inOrderArr[i])
                return false;
        }

        return true;
    }
};

int main()
{
    treeNode *root = new treeNode(4);
    root->left = new treeNode(2);
    root->right = new treeNode(7);

    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);
    // (*(*root).left).right = new treeNode();
    //         4
    //        / \
    //       2   7
    //      / \
    //     1   3

    cout << (treeNode::isValidBST(root) ? "true" : "false");
    return 0;
}