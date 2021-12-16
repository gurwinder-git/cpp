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

class solution
{
public:
    int val;
    bool ans;

    void solve(TreeNode *root)
    {
        if (!root || !this->ans)
            return;

        if (root->val != this->val)
        {
            this->ans = false;
        }

        solve(root->left);
        solve(root->right);
    }
    bool isUniValued(TreeNode *root)
    {
        this->val = root->val;
        ans = true;
        this->solve(root);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);

    solution sol;

    cout << sol.isUniValued(root);

    return 0;
}
