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
    int sum;

    void dfs(TreeNode *root, bool leftChild)
    {
        if (!root)
            return;

        dfs(root->left, true);
        dfs(root->right, false);

        if (root->left == NULL && root->right == NULL && leftChild)
        {
            this->sum += root->val;
        }
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        this->sum = 0;

        dfs(root, false);

        return this->sum;
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

    cout << sol.sumOfLeftLeaves(root);

    return 0;
}
