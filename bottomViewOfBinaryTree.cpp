#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

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
    void getWidthOfTree(TreeNode *root, int *minMax, int col)
    {
        if (root == NULL)
            return;

        *(minMax + 0) = min(*(minMax + 0), col);
        *(minMax + 1) = max(*(minMax + 1), col);

        this->getWidthOfTree((*root).left, minMax, col - 1);
        this->getWidthOfTree((*root).right, minMax, col + 1);
    }

    vector<int> bottomView(TreeNode *root)
    {
        int minMax[2] = {0, 0};
        getWidthOfTree(root, minMax, 0);

        vector<int> res(minMax[1] - minMax[0] + 1);

        queue<pair<TreeNode *, int>> helperQueue({{root, abs(minMax[0])}});

        while (!helperQueue.empty())
        {
            int sizeOfQueue = helperQueue.size();

            while (sizeOfQueue--)
            {
                pair<TreeNode *, int> curr = helperQueue.front();
                helperQueue.pop();

                int value = curr.first->val;
                int colNumber = curr.second;

                res[colNumber] = value;

                if (curr.first->left)
                    helperQueue.push(pair<TreeNode *, int>(curr.first->left, colNumber - 1));
                if (curr.first->right)
                    helperQueue.push(pair<TreeNode *, int>(curr.first->right, colNumber + 1));
            }
        }

        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;

    vector<int> res = sol.bottomView(root);

    cout << "[ ";
    for (auto v : res)
    {
        cout << " " << v << " ";
    }
    cout << " ]";

    return 0;
}
