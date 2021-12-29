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
    unordered_map<int, int> preOrderIdx;
    unordered_map<int, int> inOrderIdx;

    TreeNode *buildTree(vector<int> &preOrder, int startPreOrder, int endPreOrder, vector<int> &inOrder, int startInOrder, int endInOrder)
    {
        if (startInOrder > endInOrder)
            return NULL;

        TreeNode *root = new TreeNode(preOrder[startPreOrder]);
        if (startInOrder == endInOrder)
            return root;

        int idx = this->inOrderIdx[preOrder[startPreOrder]];
        int includedElements = idx - startInOrder;

        root->left = buildTree(preOrder, startPreOrder + 1, startPreOrder + includedElements, inOrder, startInOrder, idx - 1);

        root->right = buildTree(preOrder, startPreOrder + includedElements + 1, endPreOrder, inOrder, idx + 1, endInOrder);

        return root;
    }

    TreeNode *buildTree(vector<int> &preOrder, vector<int> &inOrder)
    {
        // storing indexes
        for (int i = 0; i < preOrder.size(); i++)
        {
            this->preOrderIdx[preOrder[i]] = i;
            this->inOrderIdx[inOrder[i]] = i;
        }

        return buildTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
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

    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};

    TreeNode *root = sol.buildTree(preOrder, inOrder);

    print(root);

    return 0;
}
