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

vector<int> rightSideView(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<int> res = rightSideView(root);

    vector<int>::iterator it = res.begin();
    for (it; it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;

    queue<TreeNode *> helperQueue({root});
    TreeNode *pre;

    while (helperQueue.size())
    {
        int widthOfLevel = helperQueue.size();
        helperQueue.push(NULL);

        while (widthOfLevel--)
        {
            pre = root;

            if (root->left)
                helperQueue.push(root->left);

            if (root->right)
                helperQueue.push(root->right);

            helperQueue.pop();
            root = helperQueue.front();
            if (root == NULL)
            {
                res.push_back(pre->val);
                helperQueue.pop();
                root = helperQueue.front();
            }
        }
    }
    return res;
}