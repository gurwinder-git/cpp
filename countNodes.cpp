#include <iostream>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int countNodes(TreeNode *root);
int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(6);

    cout << "Total nodes: " << countNodes(root);

    return 0;
}

// O(n)
//  int countNodes(TreeNode *root)
//  {
//      if (root == NULL)
//          return 0;

//     int leftCount = countNodes(root->left);
//     int rightCount = countNodes(root->right);

//     return 1 + leftCount + rightCount;
// }

// optimal solution
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    TreeNode *tempRoot = root;
    int leftNodes = 0;
    while (tempRoot)
    {
        tempRoot = tempRoot->left;
        leftNodes++;
    }

    tempRoot = root;
    int rightNodes = 0;
    while (tempRoot)
    {
        tempRoot = tempRoot->right;
        rightNodes++;
    }

    if (leftNodes == rightNodes)
        return pow(2, leftNodes) - 1;

    return countNodes(root->left) + countNodes(root->right) + 1;
}
