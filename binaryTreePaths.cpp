#include <iostream>
#include <vector>
#include <string>
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
    vector<string> res;

    void dfs(TreeNode *root, string s)
    {
        if (root == NULL)
            return;

        if (!root->left && !root->right)
            this->res.push_back(s + to_string(root->val));

        dfs(root->left, s + to_string(root->val) + "->");
        dfs(root->right, s + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return res;
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
    vector<string> res = sol.binaryTreePaths(root);

    for (string s : res)
    {
        cout << s << "     ";
    }

    return 0;
}