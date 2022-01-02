#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    // O(n) space complexity
    // Node *connect(Node *root)
    // {
    //     queue<Node *> helperQueue({root});

    //     while (!helperQueue.empty())
    //     {
    //         int sizeOfQueue = helperQueue.size();

    //         Node *pointerToPreviousElement = NULL;

    //         while (sizeOfQueue--)
    //         {
    //             Node *curr = helperQueue.front();
    //             helperQueue.pop();

    //             curr->next = pointerToPreviousElement;

    //             pointerToPreviousElement = curr;

    //             if (curr->right)
    //                 helperQueue.push(curr->right);
    //             if (curr->left)
    //                 helperQueue.push(curr->left);
    //         }
    //     }

    //     return root;
    // }

    // O(1) space complexity

    Node *connect(Node *root)
    {

        Node *levelStartRoot = root;

        for (levelStartRoot; levelStartRoot; levelStartRoot = levelStartRoot->left)
        {
            for (Node *col = levelStartRoot; col; col = col->next)
            {
                if (col->left != NULL) // then its right will always exist because it is perfect binary tree
                {
                    col->left->next = col->right;

                    if (col->next)
                    {
                        col->right->next = col->next->left;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return root;
    }
};

void print(Node *root)
{
    queue<Node *> resultQueue;

    while (root)
    {
        resultQueue.push(root);
        root = root->left;
    }

    // print element

    cout << "[ ";
    while (!resultQueue.empty())
    {
        Node *curr = resultQueue.front();

        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        resultQueue.pop();
        cout << "#,";
    }
    cout << " ]";
}

int main()
{
    Node *root = new Node(5);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution sol;

    root = sol.connect(root);

    print(root);

    return 0;
}
