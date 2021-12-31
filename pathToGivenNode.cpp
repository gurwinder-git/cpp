#include <iostream>
#include <vector>
#include <stack>

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
    void preOrder(TreeNode *root, vector<int> &res, int B)
    {
        if (root == NULL)
            return;
        res.push_back(root->val);

        if (res.back() == B)
        {
            return;
        }
        preOrder(root->left, res, B);
        preOrder(root->right, res, B);

        if (res.back() != B)
            res.pop_back();
    }
    vector<int> solve(TreeNode *root, int B)
    {
        vector<int> res;
        preOrder(root, res, B);
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;

    vector<int> res = sol.solve(root, 8);

    for (int i : res)
        cout << i << " ";

    return 0;
}
