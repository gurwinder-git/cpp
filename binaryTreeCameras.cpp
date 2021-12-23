#include <iostream>
#include <vector>
#include <utility>

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
    int totalCameras;

    int postOrder(TreeNode *root)
    {
        if (!root)
            return 1; // no need camera

        int left = postOrder(root->left);
        int right = postOrder(root->right);

        // first we have to check, is camera need by left or right child
        if (left == -1 || right == -1) // if either left or right child has no camera then
        {
            this->totalCameras++; // camera installed
            return 0;
        }

        if (left == 0 || right == 0) // if either left or right child has camera then
            return 1;                // no need camera

        return -1; // need camera
    }

    int minCameraCover(TreeNode *root)
    {
        this->totalCameras = 0;

        if (postOrder(root) == -1)
            this->totalCameras++;

        return this->totalCameras;
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);

    Solution sol;

    cout << sol.minCameraCover(root);

    return 0;
}
