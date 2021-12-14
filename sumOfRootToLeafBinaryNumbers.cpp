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

int sumRootToLeaf(TreeNode *root);
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    cout << sumRootToLeaf(root);
    return 0;
}

int solve(TreeNode *root, int sum)
{
    if (!root)
        return 0;

    int decimalSumTillCurrentnode = (root->val + (2 * sum));

    if (root->left == NULL && root->right == NULL)
        return decimalSumTillCurrentnode;

    int left = solve(root->left, decimalSumTillCurrentnode);
    int right = solve(root->right, decimalSumTillCurrentnode);

    return left + right;
}

int sumRootToLeaf(TreeNode *root)
{
    return solve(root, 0);
}