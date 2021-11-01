#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode()
    {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class solution
{
public:
    vector<TreeNode *> createTree(int start, int end)
    {
        vector<TreeNode *> treeRoots;
        if (start > end)
        {
            treeRoots.push_back(NULL);
            return treeRoots;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftSubTree = createTree(start, i - 1);
            vector<TreeNode *> rightSubTree = createTree(i + 1, end);

            for (int j = 0; j < leftSubTree.size(); j++)
                for (int k = 0; k < rightSubTree.size(); k++)
                {
                    TreeNode *root = new TreeNode(i, leftSubTree[j], rightSubTree[k]);
                    treeRoots.push_back(root);
                }
        }

        return treeRoots;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return createTree(1, n);
    }
};

void traverse(TreeNode *nodePtr);

int main()
{
    solution sol;

    vector<TreeNode *> res = sol.generateTrees(2);

    cout << "[";
    for (TreeNode *root : res)
    {
        cout << "[";
        traverse(root);
        cout << "]";
    }
    cout << "]";
    return 0;
}

void traverse(TreeNode *nodePtr)
{
    if (nodePtr == NULL)
        return;

    traverse(nodePtr->left);
    cout << nodePtr->val << " ";
    traverse(nodePtr->right);
}
