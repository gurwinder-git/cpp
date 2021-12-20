#include <iostream>
#include <queue>
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

private:
    int maxPathLenght;

public:
    int height(TreeNode *currRoot)
    {
        if (currRoot == NULL)
            return 0;

        int lheight = height(currRoot->left);
        int rheight = height(currRoot->right);

        if (!currRoot->left || currRoot->left->val != currRoot->val)
            lheight = 0;

        if (!currRoot->right || currRoot->right->val != currRoot->val)
            rheight = 0;

        this->maxPathLenght = max(this->maxPathLenght, lheight + rheight);

        return 1 + max(lheight, rheight);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        this->maxPathLenght = 0;
        this->height(root);
        return this->maxPathLenght;
    }
};
int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(3);
    (*root).right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.longestUnivaluePath(root);

    return 0;
}