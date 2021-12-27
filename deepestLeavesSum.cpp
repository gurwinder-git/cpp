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
    int ans;
    int findMaxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);

        return max(left, right) + 1;
    }

    void solve(TreeNode *root, int &maxDepth)
    {
        if (!root)
            return;

        maxDepth--;
        if (maxDepth == 0)
        {
            this->ans += root->val;
        }

        solve(root->left, maxDepth);
        solve(root->right, maxDepth);
        maxDepth++;
    }

    // also solved by level order sum
    int deepestLeavesSum(TreeNode *root)
    {
        this->ans = 0;
        int maxDepth = findMaxDepth(root);

        solve(root, maxDepth);
        return ans;
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
    root->right->right = new TreeNode(1);

    Solution sol;

    cout << sol.deepestLeavesSum(root);

    return 0;
}
