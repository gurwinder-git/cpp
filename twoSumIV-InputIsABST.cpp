#include <iostream>
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

class BSTItr
{
public:
    stack<TreeNode *> ascendingOrderNodes;
    stack<TreeNode *> decendingOrderNodes;

    BSTItr(TreeNode *node)
    {
        this->insertLeftNodes(node);
        this->insertRightNodes(node);
    }

    void insertLeftNodes(TreeNode *node)
    {
        while (node)
        {
            this->ascendingOrderNodes.push(node);
            node = node->left;
        }
    }
    void insertRightNodes(TreeNode *node)
    {
        while (node)
        {
            this->decendingOrderNodes.push(node);
            node = node->right;
        }
    }

    TreeNode *next()
    {
        TreeNode *curr = this->ascendingOrderNodes.top();
        this->ascendingOrderNodes.pop();
        this->insertLeftNodes(curr->right);
        return curr;
    }

    TreeNode *previous()
    {
        TreeNode *curr = this->decendingOrderNodes.top();
        this->decendingOrderNodes.pop();
        this->insertRightNodes(curr->left);
        return curr;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTItr itr = root;

        TreeNode *left = itr.next();
        TreeNode *right = itr.previous();

        while (left != right)
        {
            int leftValue = left->val;
            int rightValue = right->val;

            if (leftValue + rightValue == k)
                return true;
            else if (leftValue + rightValue < k)
            {
                left = itr.next();
            }
            else
            {
                right = itr.previous();
            }
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;

    cout << "is pair exist: " << (sol.findTarget(root, 8) ? "yes" : "no");

    return 0;
}
