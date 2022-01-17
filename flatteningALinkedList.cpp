#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/* Node structure  used in the program
 */

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    // O(nlogn) solution
    // Node *flatten(Node *root)
    // {
    //     priority_queue<int> pq;

    //     Node *curr = root, *next = root;

    //     while (curr)
    //     {
    //         next = curr->next;

    //         while (curr)
    //         {
    //             pq.push(curr->data);
    //             curr = curr->bottom;
    //         }

    //         curr = next;
    //     }

    //     Node *head = NULL;
    //     while (!pq.empty())
    //     {
    //         int val = pq.top();
    //         pq.pop();

    //         if (head == nullptr)
    //             head = new Node(val);
    //         else
    //         {
    //             Node *newNode = new Node(val);
    //             newNode->bottom = head;
    //             head = newNode;
    //         }
    //     }

    //     return head;
    // }

    // O(m+2m+3m+4m....nm)
    Node *flatten(Node *root)
    {
        if (!root || !root->next)
            return root;
        stack<Node *> stk;

        while (root)
        {
            stk.push(root);
            root = root->next;
        }

        Node *originalHead = NULL;

        Node *curr = new Node(-1);
        Node *tempHead = curr;

        Node *l1 = stk.top();
        stk.pop();
        Node *l2 = stk.top();
        stk.pop();

        while (true)
        {
            l1->next = NULL;
            l2->next = NULL;

            while (l1 != NULL && l2 != NULL)
            {
                Node *temp;
                if (l1->data < l2->data)
                {
                    temp = l1;
                    l1 = l1->bottom;
                }
                else
                {
                    temp = l2;
                    l2 = l2->bottom;
                }
                curr->bottom = temp;
                curr = curr->bottom;
            }
            if (l1)
                curr->bottom = l1;
            else
                curr->bottom = l2;

            originalHead = tempHead->bottom;
            tempHead = new Node(-1);
            curr = tempHead;

            if (!stk.empty())
            {
                l1 = originalHead;
                l2 = stk.top();
                stk.pop();
            }
            else
                break;
        }

        return originalHead;
    }
};

int main()
{
    Node *head = new Node(1);
    head->bottom = new Node(3);
    head->bottom->bottom = new Node(4);
    head->bottom->bottom->bottom = new Node(5);

    head->next = new Node(12);
    head->next->bottom = new Node(15);
    head->next->bottom->bottom = new Node(19);

    head->next->next = new Node(20);
    head->next->bottom = new Node(30);
    head->next->bottom->bottom = new Node(40);
    head->next->bottom->bottom->bottom = new Node(50);

    Solution sol;

    head = sol.flatten(head);

    while (head)
    {
        cout << head->data << "  ";
        head = head->bottom;
    }

    return 0;
}