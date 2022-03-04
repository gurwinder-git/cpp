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

class Solution
{
public:
    void preOrder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        cout << root->val << "  ";
        preOrder(root->left);
        preOrder(root->right);
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return NULL;

        if (root1 && root2)
        {
            root1->val += root2->val;

            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        else if (root2)
        {
            return root2;
        }

        return root1;
    }

    // making new Tree
    //  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    //  {
    //      if (!root1 && !root2)
    //          return NULL;

    //     TreeNode *node;

    //     if (root1 && root2)
    //     {
    //         node = new TreeNode(root1->val + root2->val);
    //     }
    //     else if (root1)
    //     {
    //         node = new TreeNode(root1->val);
    //     }
    //     else
    //     {
    //         node = new TreeNode(root2->val);
    //     }

    //     TreeNode *root1Left = root1 ? root1->left : root1;
    //     TreeNode *root1Right = root1 ? root1->right : root1;

    //     TreeNode *root2Left = root2 ? root2->left : root2;
    //     TreeNode *root2Right = root2 ? root2->right : root2;

    //     node->left = mergeTrees(root1Left, root2Left);
    //     node->right = mergeTrees(root1Right, root2Right);

    //     return node;
    // }
};

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);

    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution sol;

    TreeNode *root3 = sol.mergeTrees(root1, root2);

    sol.preOrder(root3);
    return 0;
}
