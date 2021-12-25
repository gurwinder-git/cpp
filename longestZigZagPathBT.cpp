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
    int longestPath;

    int dfs(TreeNode *root, bool isLeft)
    {
        if (!root)
            return 0;

        int leftVal = dfs(root->left, true);
        int rightVal = dfs(root->right, false);

        this->longestPath = max({this->longestPath, leftVal, rightVal});

        if (isLeft)
            return rightVal + 1;
        return leftVal + 1;
    }
    int longestZigZag(TreeNode *root)
    {
        this->longestPath = 0;
        this->dfs(root, false);
        return longestPath;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;

    cout << sol.longestZigZag(root);

    return 0;
}
