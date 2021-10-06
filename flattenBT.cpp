#include <iostream>
#include <stack>
#include <queue>
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
        queue<treeNode *> inOrderNodes;
        stack<treeNode *> helperStack;

        treeNode *tempRoot = root;

        while (tempRoot || !helperStack.empty())
        {
            if (tempRoot)
            {
                inOrderNodes.push(tempRoot);
                helperStack.push(tempRoot);
                tempRoot = tempRoot->left;
            }
            else
            {
                tempRoot = helperStack.top();
                helperStack.pop();
                tempRoot = tempRoot->right;
            }
        }

        treeNode *current;
        while (!inOrderNodes.empty())
        {
            current = inOrderNodes.front();
            inOrderNodes.pop();

            current->left = NULL;
            current->right = inOrderNodes.front();
        }
        current->right = NULL;
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