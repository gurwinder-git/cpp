#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    static void createNode(ListNode *&resultHead, int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = resultHead;
        resultHead = newNode;
    }

    static void checkIfStacksNotEmpty(stack<ListNode *> &stk, ListNode *&resultHead, int &carry)
    {
        while (!stk.empty())
        {
            int sum = stk.top()->data + carry;
            createNode(resultHead, sum % 10);
            carry = sum / 10;
            stk.pop();
        }
    }

    static ListNode *addTwoLinkedList(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> l1Stack;
        stack<ListNode *> l2Stack;

        ListNode *resultHead = NULL;

        while (l1 || l2)
        {
            if (l1)
            {
                l1Stack.push(l1);
                l1 = l1->next;
            }
            if (l2)
            {
                l2Stack.push(l2);
                l2 = l2->next;
            }
        }

        int carry = 0;

        while (!l1Stack.empty() && !l2Stack.empty())
        {
            int sum = l1Stack.top()->data + l2Stack.top()->data + carry;
            //insert result in new node
            createNode(resultHead, sum % 10);
            //set carry
            carry = sum / 10;
            //pop pointers
            l1Stack.pop();
            l2Stack.pop();
        }

        checkIfStacksNotEmpty(l1Stack, resultHead, carry);
        checkIfStacksNotEmpty(l2Stack, resultHead, carry);

        if (carry > 0)
            createNode(resultHead, carry);

        return resultHead;
    }
};

int main()
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(6);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(4);

    ListNode *resultHead = ListNode::addTwoLinkedList(l1, l2);

    while (resultHead)
    {
        cout << resultHead->data;
        resultHead = resultHead->next;
    }

    return 0;
}