#include <iostream>
#include <vector>

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
    TreeNode *constructBST(vector<int> &nums, int lb, int ub)
    {
        if (lb > ub)
            return NULL;

        TreeNode *left = constructBST(nums, lb, ((lb + ub) / 2) - 1);

        TreeNode *right = constructBST(nums, ((lb + ub) / 2) + 1, ub);

        TreeNode *node = new TreeNode(nums[(lb + ub) / 2], left, right);

        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return constructBST(nums, 0, nums.size() - 1);
    }

    void inOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        inOrderTraversal(root->left);
        cout << root->val << "  ";
        inOrderTraversal(root->right);
    }
};

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(arr);
    sol.inOrderTraversal(root);
    return 0;
}