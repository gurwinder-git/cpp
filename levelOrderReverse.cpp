#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrderBottom(TreeNode *root);

int main()
{
    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<vector<int>> res = levelOrderBottom(root);

    for (vector<int> obj : res)
        for (int num : obj)
            cout << num << "  ";

    return 0;
}

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;

    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    TreeNode *current;
    int length;

    while (!nodeQueue.empty())
    {
        vector<int> level;
        length = nodeQueue.size();

        for (int i = 0; i < length; i++)
        {
            current = nodeQueue.front();
            level.push_back(current->val);

            if (current->left)
                nodeQueue.push(current->left);
            if (current->right)
                nodeQueue.push(current->right);
            nodeQueue.pop();
        }

        res.push_back(level);
    }

    reverse(res.begin(), res.end());

    return res;
}