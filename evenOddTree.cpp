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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> helperQueue;
        int evenOdd = 0;

        helperQueue.push(root);

        int increasingOrder = INT_MIN;
        int decreasingOrder = INT_MAX;

        while (!helperQueue.empty())
        {
            int currentSizeOfQueue = helperQueue.size();

            while (currentSizeOfQueue)
            {

                TreeNode *currNode = helperQueue.front();
                helperQueue.pop();

                // for even level index
                if (evenOdd % 2 == 0)
                {
                    if (!(currNode->val % 2 > 0 && currNode->val > increasingOrder))
                        return false;
                    increasingOrder = currNode->val;
                }
                // for odd level index
                else
                {
                    if (!(currNode->val % 2 == 0 && currNode->val < decreasingOrder))
                        return false;
                    decreasingOrder = currNode->val;
                }
                if (currNode->left)
                    helperQueue.push(currNode->left);
                if (currNode->right)
                    helperQueue.push(currNode->right);

                currentSizeOfQueue--;
            }
            increasingOrder = INT_MIN;
            decreasingOrder = INT_MAX;
            evenOdd++;
        }

        return true;
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
    cout << sol.isEvenOddTree(root);

    return 0;
}