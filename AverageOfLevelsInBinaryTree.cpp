#include <iostream>
#include <vector>
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

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q({root});
        vector<double> res;

        while (!q.empty())
        {
            int totalElements = q.size();
            int size = totalElements;
            long int totalSum = 0;

            while (size--)
            {
                TreeNode *curr = q.front();
                q.pop();

                totalSum += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            res.push_back((double)totalSum / totalElements);
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    Solution sol;

    vector<double> res = sol.averageOfLevels(root);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "  ";

    return 0;
}
