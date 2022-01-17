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
    // O(n) solution
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;

        Node *cloneHead = new Node(-1);
        Node *cloneCurr = cloneHead;

        Node *tempHeadCurr = head;
        while (tempHeadCurr)
        {
            Node *newNode = new Node(tempHeadCurr->val);
            cloneCurr->next = newNode;

            // map newNode to its corresponding node
            mp.insert({tempHeadCurr, newNode});

            // move forward
            tempHeadCurr = tempHeadCurr->next;
            cloneCurr = cloneCurr->next;
        }
        cloneHead = cloneHead->next;
        cloneCurr = cloneHead;

        tempHeadCurr = head;

        while (tempHeadCurr)
        {
            Node *rand = tempHeadCurr->random;
            Node *randomToNode = mp[rand];
            cloneCurr->random = randomToNode;

            // move forward
            tempHeadCurr = tempHeadCurr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
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
        if (deepCloneHead == head)
        {
            cout << "wrong output";
            break;
        }
        deepCloneHead->val = deepCloneHead->val * -1;
        cout << deepCloneHead->val << "  ";
        deepCloneHead = deepCloneHead->next;
    }
    cout << endl;

    while (head)
    {
        cout << head->val << "  ";
        head = head->next;
    }

    return 0;
}