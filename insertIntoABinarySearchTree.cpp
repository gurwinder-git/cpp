#include <iostream>
#include <vector>
#include <algorithm>

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

class Solution
{
public:
    TreeNode *findNode(TreeNode *root, TreeNode *parent, int &val)
    {
        if (!root)
            return parent;

        return root->val < val ? findNode(root->right, root, val) : findNode(root->left, root, val);
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode *resRoot = findNode(root, NULL, val);

        if (resRoot->val > val)
            resRoot->left = new TreeNode(val);
        else
            resRoot->right = new TreeNode(val);

        return root;
    }
};

void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << "  ";
    inOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;

    root = sol.insertIntoBST(root, 9);

    inOrder(root);

    return 0;
}
