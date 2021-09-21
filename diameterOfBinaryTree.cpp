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

bool isSymmetric3(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    bool res = isSymmetric3(root);

    cout << res;

    return 0;
}
bool isSymmetric3(TreeNode *root)
{
    if (!root)
        return true;

    queue<TreeNode *> nodeAddress({root->right, root->left});

    TreeNode *l, *r;
    while (!nodeAddress.empty())
    {
        r = nodeAddress.front();
        nodeAddress.pop();
        l = nodeAddress.front();
        nodeAddress.pop();

        //   0 && 1 || 1 && 0
        //   1 && 0 || 0 && 1
        if (!r && l || r && !l)
            return false;

        if (r && l)
        {
            if (r->val != l->val)
                return false;

            nodeAddress.push(r->right);
            nodeAddress.push(l->left);
            nodeAddress.push(r->left);
            nodeAddress.push(l->right);
        }
    }
    return true;
}
