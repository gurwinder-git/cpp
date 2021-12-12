#include <iostream>

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

bool isCousins(TreeNode *root, int x, int y);
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << (isCousins(root, 4, 7) ? "yes cousin" : "no cousin");
    return 0;
}

int solve(TreeNode *root, int nodeVal, int &parent, int height)
{
    if (!root)
        return 0;

    if (root->val == nodeVal)
        return height;

    parent = root->val;
    int left = solve(root->left, nodeVal, parent, height + 1);

    if (left != 0)
        return left;

    parent = root->val;
    int right = solve(root->right, nodeVal, parent, height + 1);
    return right;
}

bool isCousins(TreeNode *root, int x, int y)
{
    int parentX = -1;
    int heightX = solve(root, x, parentX, 0);

    int parentY = -1;
    int heightY = solve(root, y, parentY, 0);

    if ((parentX != parentY) && (heightX == heightY))
        return true;
    return false;
}
