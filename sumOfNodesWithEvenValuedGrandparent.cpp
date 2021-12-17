#include <iostream>
#include <vector>
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

class Solution
{
public:
    int sum = 0;

    // brute force
    void solve(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left != NULL && root->left->left != NULL)
        {
            if (root->left->left->val % 2 == 0)
                this->sum += root->left->left->val;
        }

        if (root->left != NULL && root->left->right != NULL)
        {
            if (root->val % 2 == 0)
            {
                this->sum += root->left->right->val;
            }
        }

        if (root->right != NULL && root->right->left != NULL)
        {
            if (root->val % 2 == 0)
                this->sum += root->right->left->val;
        }

        if (root->right != NULL && root->right->right != NULL)
        {
            if (root->val % 2 == 0)
                this->sum += root->right->right->val;
        }
        solve(root->left);
        solve(root->right);
    }

    // optimal
    void solve(TreeNode *current, TreeNode *parent, TreeNode *grandParent)
    {
        if (!current)
            return;

        if (grandParent && grandParent->val % 2 == 0)
        {
            this->sum += current->val;
        }

        solve(current->left, current, parent);
        solve(current->right, current, parent);
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        this->solve(root, NULL, NULL);
        // this->solve(root);
        return this->sum;
    }
};
int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.sumEvenGrandparent(root);

    return 0;
}