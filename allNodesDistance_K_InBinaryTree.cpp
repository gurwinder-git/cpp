#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parentOf;
        parentOf.insert({root, NULL}); // root has no parent

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(root);

        // store parent of all nodes;
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            visited.insert({currNode, false});
            q.pop();

            if (currNode->left)
            {
                parentOf.insert({currNode->left, currNode});
                q.push(currNode->left);
            }
            if (currNode->right)
            {
                parentOf.insert({currNode->right, currNode});
                q.push(currNode->right);
            }
        }

        // bfs

        q.push(target);
        visited[target] = true;

        while (!q.empty() && k > 0)
        {
            int qSize = q.size();

            while (qSize--)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left != NULL && visited[curr->left] == false)
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right != NULL && visited[curr->right] == false)
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parentOf[curr] != NULL && visited[parentOf[curr]] == false)
                {
                    visited[parentOf[curr]] = true;
                    q.push(parentOf[curr]);
                }
            }
            k--;
        }

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    vector<int> res = sol.distanceK(root, root->left, 2);

    for (int i : res)
        cout << i << "  ";
    return 0;
}