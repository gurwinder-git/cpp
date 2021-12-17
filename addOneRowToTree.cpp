#include <iostream>
#include <queue>
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode *> helperQueue;

        helperQueue.push(root);

        while (depth > 2)
        {
            int queueSize = helperQueue.size();
            while (queueSize)
            {

                TreeNode *curr = helperQueue.front();
                helperQueue.pop();

                if (curr->left != NULL)
                    helperQueue.push(curr->left);

                if (curr->right != NULL)
                    helperQueue.push(curr->right);

                queueSize--;
            }

            depth--;
        }

        while (!helperQueue.empty())
        {
            TreeNode *curr = helperQueue.front();
            helperQueue.pop();

            TreeNode *leftChild = new TreeNode(val);
            leftChild->left = curr->left;

            curr->left = leftChild;

            TreeNode *rightChild = new TreeNode(val);
            rightChild->right = curr->right;

            curr->right = rightChild;
        }

        return root;
    }

    void levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return;

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
                cout << current->val << "  ";

                if (current->left)
                    nodeQueue.push(current->left);
                if (current->right)
                    nodeQueue.push(current->right);
                nodeQueue.pop();
            }

            res.push_back(level);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(2);

    solution sol;

    root = sol.addOneRow(root, 1, 3);

    sol.levelOrder(root);
    return 0;
}
