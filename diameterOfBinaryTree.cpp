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

    int height(TreeNode *currRoot)
    {
        if (currRoot == NULL)
            return 0;

        int lHeight = height(currRoot->left);
        int rHeight = height(currRoot->right);

        ans = max(ans, lHeight + rHeight);

        return 1 + max(lHeight, rHeight);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        this->ans = 0;
        this->height(root);
        return ans;
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
    cout << sol.diameterOfBinaryTree(root);

    return 0;
}