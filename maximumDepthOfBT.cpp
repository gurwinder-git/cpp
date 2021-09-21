#include <iostream>
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

int maxDepth(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    int res = maxDepth(root);

    cout << res;

    return 0;
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;

    q.push(root);
    int maxDepth = 0;

    while (!q.empty())
    {
        int levelWidth = q.size();
        ++maxDepth;
        while (levelWidth--)
        {
            TreeNode *current = q.front();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            q.pop();
        }
    }
    return maxDepth;
}