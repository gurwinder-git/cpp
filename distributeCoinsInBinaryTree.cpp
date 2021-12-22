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
    int moves;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        this->moves += abs(left) + abs(right);

        return (root->val + left + right - 1);
    }

    int distributeCoins(TreeNode *root)
    {
        this->moves = 0;
        this->dfs(root);
        return moves;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);

    Solution sol;

    cout << sol.distributeCoins(root);

    return 0;
}
