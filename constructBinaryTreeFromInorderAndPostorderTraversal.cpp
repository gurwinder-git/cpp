#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> idxOfInorderElements;

    TreeNode *buildTree(vector<int> &inorder, int inorderStart, int inorderEnd, vector<int> &postorder, int postorderStart, int postorderEnd)
    {
        if (postorderStart > postorderEnd)
            return NULL;

        TreeNode *node = new TreeNode(postorder[postorderEnd]);

        if (postorderStart == postorderEnd)
            return node;

        int idx = this->idxOfInorderElements[postorder[postorderEnd]];
        int includeElemetsInPostorder = inorderEnd - idx;

        node->left = this->buildTree(inorder, inorderStart, idx - 1, postorder, postorderStart, postorderEnd - includeElemetsInPostorder - 1);

        node->right = this->buildTree(inorder, idx + 1, inorderEnd, postorder, postorderEnd - includeElemetsInPostorder, postorderEnd - 1);

        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // store indexes of inorder and postorder vectors

        for (int i = 0; i < inorder.size(); i++)
        {
            this->idxOfInorderElements[inorder[i]] = i;
        }

        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

void print(TreeNode *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->val << "  ";
    print(root->right);
}

int main()
{

    Solution sol;

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = sol.buildTree(inorder, postorder);

    print(root);

    return 0;
}
