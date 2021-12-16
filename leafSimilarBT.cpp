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

bool leafSimilar(TreeNode *root1, TreeNode *root2);
int main()
{
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);

    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);
    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(7);

    cout << leafSimilar(root1, root2);

    return 0;
}

void solve(TreeNode *root, vector<int> &v)
{
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
        v.push_back(root->val);
    else
    {
        solve(root->left, v);
        solve(root->right, v);
    }
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1;
    vector<int> v2;

    solve(root1, v1);
    solve(root2, v2);

    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}