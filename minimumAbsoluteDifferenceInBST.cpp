#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    int minDiff = INT_MAX;
    int previousVal = -1;

    int getMinimumDifference(TreeNode *root)
    {
        if (root->left)
            getMinimumDifference(root->left);

        if (previousVal != -1)
            this->minDiff = min(this->minDiff, root->val - this->previousVal);

        this->previousVal = root->val;

        if (root->right)
            getMinimumDifference(root->right);

        return this->minDiff;
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

    cout << sol.getMinimumDifference(root);

    return 0;
}
