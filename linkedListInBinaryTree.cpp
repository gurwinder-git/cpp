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

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool solve(ListNode *head, TreeNode *root)
    {
        if (head == NULL)
            return true;

        if (root == NULL)
            return false;

        if (root->val == head->val && (solve(head->next, root->left) || solve(head->next, root->right)))
            return true;
        else
            return false;
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        queue<TreeNode *> helperQueue({root});

        while (!helperQueue.empty())
        {
            int sizeOfQueue = helperQueue.size();

            while (sizeOfQueue)
            {
                TreeNode *curr = helperQueue.front();
                helperQueue.pop();

                if (curr->val == head->val)
                {
                    if (solve(head, curr))
                    {
                        return true;
                    }
                }
                if (curr->left)
                    helperQueue.push(curr->left);
                if (curr->right)
                    helperQueue.push(curr->right);
                sizeOfQueue--;
            }
        }

        return false;
    }
};
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);

    TreeNode *root = new TreeNode(3);
    (*root).left = new TreeNode(4);
    (*root).right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.isSubPath(head, root);

    return 0;
}