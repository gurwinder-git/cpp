#include <iostream>
#include <queue>
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

bool isBalanced(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    bool res = isBalanced(root);
    cout << res << "  ";

    return 0;
}

//recursive

int maxHeight(TreeNode *root, bool &res)
{
    if (!root)
        return 0;

    int leftHeight = maxHeight(root->left, res);
    int rightHeight = maxHeight(root->right, res);

    int bf = leftHeight - rightHeight; //bf = balance facter
    if (!(bf >= -1 && bf <= 1))
        res = false;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root)
{
    bool res = true;
    maxHeight(root, res);
    return res;
}