#include <iostream>
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

int rangeSumBST(TreeNode *root, int low, int high);

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << rangeSumBST(root, 3, 7);

    return 0;
}

void solve(TreeNode *root, int &low, int &high, int &ans)
{
    if (!root)
        return;

    if (root->val >= low && root->val <= high)
    {
        ans += root->val;
    }

    if (root->val > low)
        solve(root->left, low, high, ans);
    if (root->val < high)
        solve(root->right, low, high, ans);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    solve(root, low, high, ans);
    return ans;
}