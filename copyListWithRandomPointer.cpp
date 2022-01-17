#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    // O(n) space solution
    // Node *copyRandomList(Node *head)
    // {
    //     unordered_map<Node *, Node *> mp;

    //     Node *cloneHead = new Node(-1);
    //     Node *clonecurr2 = cloneHead;

    //     Node *tempHeadcurr2 = head;
    //     while (tempHeadcurr2)
    //     {
    //         Node *newNode = new Node(tempHeadcurr2->val);
    //         clonecurr2->next = newNode;

    //         // map newNode to its corresponding node
    //         mp.insert({tempHeadcurr2, newNode});

    //         // move forward
    //         tempHeadcurr2 = tempHeadcurr2->next;
    //         clonecurr2 = clonecurr2->next;
    //     }
    //     cloneHead = cloneHead->next;
    //     clonecurr2 = cloneHead;

    //     tempHeadcurr2 = head;

    //     while (tempHeadcurr2)
    //     {
    //         Node *rand = tempHeadcurr2->random;
    //         Node *randomToNode = mp[rand];
    //         clonecurr2->random = randomToNode;

    //         // move forward
    //         tempHeadcurr2 = tempHeadcurr2->next;
    //         clonecurr2 = clonecurr2->next;
    //     }

    //     return cloneHead;
    // }

    // O(1) space
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *curr1 = head;
        Node *newHead = NULL;
        Node *curr2 = NULL;

        while (curr1)
        {
            Node *newNode = new Node(curr1->val);
            newNode->next = curr1->next;
            curr1->next = newNode;

            curr1 = curr1->next->next;
        }
        newHead = head->next;
        curr1 = head;
        curr2 = head->next;

        // cout << curr1->val << endl;
        // cout << curr2->next->val << endl;

        while (curr2)
        {
            Node *linkToRan = curr1->random;
            curr2->random = linkToRan == NULL ? NULL : linkToRan->next;
            // move
            curr1 = curr2->next;
            curr2 = curr2->next == NULL ? NULL : curr2->next->next;
        }

        // resetting
        curr1 = head;
        curr2 = newHead;
        while (curr2)
        {
            curr1->next = curr2->next;
            curr1 = curr1->next;
            if (curr2->next)
            {
                curr2->next = curr2->next->next;
            }
            curr2 = curr2->next;
        }

        return newHead;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    head->random = head->next->next;
    head->next->random = head->next->next->next->next->next->next;
    head->next->next->next->next->next->random = head;
    head->next->next->next->random = head->next->next->next->next;

    Solution sol;
    Node *deepCloneHead = sol.copyRandomList(head);

    while (deepCloneHead)
    {
        deepCloneHead->val = deepCloneHead->val * -1;
        cout << deepCloneHead->val << "  ";
        deepCloneHead = deepCloneHead->next;
    }
    cout << endl;

    while (head)
    {
        cout << head->val << "   ";
        head = head->next;
    }

    return 0;
}