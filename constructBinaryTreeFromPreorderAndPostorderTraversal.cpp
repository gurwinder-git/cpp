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
    TreeNode *constructFromPrePost(vector<int> &preorder, int preStartIndex, int preEndIndex, vector<int> &postorder, int postStartIndex, int postEndIndex)
    {
        if (preStartIndex > preEndIndex || postStartIndex > postEndIndex)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStartIndex]);

        if (postStartIndex == postEndIndex) // also write preStartIndex and preEndIndex
            return root;

        int idx;

        for (int i = postStartIndex; i <= postEndIndex; i++)
        {
            if (preorder[preStartIndex + 1] == postorder[i])
            {
                idx = i;
                break;
            }
        }

        int totalNumberOfElements = idx - postStartIndex;

        root->left = constructFromPrePost(preorder, preStartIndex + 1, preStartIndex + 1 + totalNumberOfElements, postorder, postStartIndex, idx);

        root->right = constructFromPrePost(preorder, preStartIndex + totalNumberOfElements + 2, preEndIndex, postorder, idx + 1, postEndIndex - 1);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return constructFromPrePost(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
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

    Solution sol;

    vector<int> preOrder = {1, 2, 4, 3};
    vector<int> postOrder = {4, 3, 2, 1};

    TreeNode *root = sol.constructFromPrePost(preOrder, postOrder);

    inOrder(root);

    return 0;
}
