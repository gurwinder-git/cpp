#include <iostream>
#include <vector>
#include <stack>

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
    int sum;

    void reverseInOrder(TreeNode *root)
    {
        if (!root)
            return;

        this->reverseInOrder(root->right);
        this->sum += root->val;
        root->val = this->sum;
        this->reverseInOrder(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        this->sum = 0;
        this->reverseInOrder(root);
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
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;

    inOrder(sol.convertBST(root));

    return 0;
}
