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
    int index;
    TreeNode *bstFromPreorder(vector<int> &preorder, int minRange, int maxRange)
    {
        if (this->index >= preorder.size() || preorder[this->index] < minRange || preorder[this->index] > maxRange)
            return NULL;

        TreeNode *node = new TreeNode(preorder[this->index++]);

        node->left = this->bstFromPreorder(preorder, minRange, node->val);
        node->right = this->bstFromPreorder(preorder, node->val, maxRange);

        return node;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        this->index = 0;
        return this->bstFromPreorder(preorder, INT_MIN, INT_MAX);
    }
};

void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << "  ";
    inOrder(root->right);
}

int main()
{
    vector<int> preorderTraversal = {8, 5, 1, 7, 10, 12};

    Solution sol;

    inOrder(sol.bstFromPreorder(preorderTraversal));

    return 0;
}
