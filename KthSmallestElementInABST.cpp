#include <iostream>
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

class Solution
{
public:
    int dfs(TreeNode *root, int &k)
    {
        if (!root)
            return 0;

        int left = dfs(root->left, k);

        if (left != 0)
            return left;

        k--;
        if (k == 0)
            return root->val;

        int right = dfs(root->right, k);
        return right;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        return dfs(root, k);
    }
};

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

    cout << sol.kthSmallest(root, 3);

    return 0;
}
