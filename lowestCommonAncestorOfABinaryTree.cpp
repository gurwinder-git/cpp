#include <iostream>
#include <vector>
#include <utility>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *&p, TreeNode *&q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *left = this->lowestCommonAncestor(root->left, p, q);
        TreeNode *right = this->lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        return root;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << sol.lowestCommonAncestor(root, root->left->left, root->right->right)->val;

    return 0;
}
