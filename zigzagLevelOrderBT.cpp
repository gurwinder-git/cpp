#include <iostream>
#include <stack>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root);

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    vector<vector<int>> res = zigzagLevelOrder(root);

    vector<vector<int>>::iterator it = res.begin();

    for (it; it != res.end(); it++)
    {
        for (int i : *it)
        {
            cout << i << " ";
        }
    }

    return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;

    int seletor = 1;
    stack<TreeNode *> evenStk;
    stack<TreeNode *> oddStk({root});

    // int lvlWidth;

    while (evenStk.size() || oddStk.size())
    {
        vector<int> levelValues;

        if (seletor % 2 == 0)
        {
            // lvlWidth = evenStk.size();

            while (evenStk.size())
            {
                root = evenStk.top();
                evenStk.pop();
                if (root->right)
                    oddStk.push(root->right);
                if (root->left)
                    oddStk.push(root->left);

                levelValues.push_back(root->val);
            }
        }
        else
        {
            // lvlWidth = oddStk.size();

            while (oddStk.size())
            {
                root = oddStk.top();
                oddStk.pop();
                if (root->left)
                    evenStk.push(root->left);

                if (root->right)
                    evenStk.push(root->right);

                levelValues.push_back(root->val);
            }
        }

        res.push_back(levelValues);
        seletor++;
    }

    return res;
}