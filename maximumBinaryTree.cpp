#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;

        int indexOfLargestElement = start;
        int largestElement = nums[start];

        for (int i = start + 1; i <= end; i++)
        {
            if (nums[i] > largestElement)
            {
                largestElement = nums[i];
                indexOfLargestElement = i;
            }
        }

        TreeNode *node = new TreeNode(largestElement);
        if (start == end)
            return node;

        node->left = constructMaximumBinaryTree(nums, start, indexOfLargestElement - 1);
        node->right = constructMaximumBinaryTree(nums, indexOfLargestElement + 1, end);

        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
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

    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution sol;

    TreeNode *root = sol.constructMaximumBinaryTree(nums);
    inOrder(root);

    return 0;
}
