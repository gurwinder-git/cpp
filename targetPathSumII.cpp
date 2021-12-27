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
    int targetSum;
    vector<vector<int>> res;

    void preOrder(TreeNode *root, vector<int> &row)
    {
        if (!root)
            return;

        this->targetSum -= root->val;
        row.push_back(root->val);

        preOrder(root->left, row);
        preOrder(root->right, row);

        if (this->targetSum == 0 && root->left == NULL && root->right == NULL)
        {
            this->res.push_back(row);
        }
        this->targetSum += root->val;
        row.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        this->targetSum = targetSum;
        vector<int> row;
        preOrder(root, row);
        return this->res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution sol;

    vector<vector<int>> res = sol.pathSum(root, 10);

    for (vector<int> v : res)
    {
        for (int i : v)
        {
            cout << i << "  ";
        }
        cout << endl;
    }

    return 0;
}
