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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;

        if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;

        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(5);

    TreeNode *subRoot = new TreeNode(5);
    subRoot->left = new TreeNode(7);
    subRoot->right = new TreeNode(2);

    Solution sol;

    cout << sol.isSubtree(root, subRoot);

    return 0;
}
