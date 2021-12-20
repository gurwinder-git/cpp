#include <iostream>
#include <queue>
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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> nodes({root});

        int currlevel = 0;
        int maxSum = INT_MIN;
        int res = 0;

        while (!nodes.empty())
        {
            currlevel++;
            int totalNodes = nodes.size();
            int lvlSum = 0;
            while (totalNodes--)
            {
                TreeNode *currNode = nodes.front();
                nodes.pop();

                lvlSum += currNode->val;

                if (currNode->left)
                    nodes.push(currNode->left);
                if (currNode->right)
                    nodes.push(currNode->right);
            }

            if (lvlSum > maxSum)
            {
                maxSum = lvlSum;
                res = currlevel;
            }
        }
        return res;
    }
};

int main()
{

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.maxLevelSum(root);

    return 0;
}