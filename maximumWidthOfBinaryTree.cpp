#include <iostream>
#include <queue>
#include <utility>
#include <climits>

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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push(pair<TreeNode *, unsigned long long>(root, 0));
        unsigned long long maxWidth = 1;

        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {
                pair<TreeNode *, unsigned long long> curr = q.front();
                q.pop();

                if (curr.first->left)
                    q.push(pair<TreeNode *, unsigned long long>(curr.first->left, curr.second * 2));
                if (curr.first->right)
                    q.push(pair<TreeNode *, unsigned long long>(curr.first->right, (curr.second * 2) + 1));
            }

            if (!q.empty())
            {
                maxWidth = max(q.back().second - q.front().second + 1, maxWidth);
            }
        }

        return maxWidth;
    }
};

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(3);
    (*root).right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.widthOfBinaryTree(root);

    return 0;
}