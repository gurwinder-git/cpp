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
    bool preOrder(TreeNode *root, int &targetSum)
    {
        if (root == NULL)
            return false;

        targetSum -= root->val;

        if ((targetSum == 0 && root->left == NULL && root->right == NULL) || preOrder(root->left, targetSum) || preOrder(root->right, targetSum))
        {
            return true;
        }

        targetSum += root->val;
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return preOrder(root, targetSum);
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution sol;

    cout << sol.hasPathSum(root, 10);

    return 0;
}
