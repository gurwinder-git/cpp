#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    static void addOneToLinkedList(node *&head)
    {
        node *tempHead = head;
        stack<node *> helperStack;

        while (tempHead)
        {
            helperStack.push(tempHead);
            tempHead = tempHead->next;
        }

        int carry = 0;

        while (!helperStack.empty())
        {
            int sum = helperStack.top()->data + 1;
            helperStack.top()->data = sum % 10;
            carry = sum / 10;
            helperStack.pop();

            if (carry == 0)
                break;
        }

        if (carry > 0)
        {
            tempHead = new node(carry);
            tempHead->next = head;
            head = tempHead;
        }
    }
};

int main()
{
    node *head = new node(9);
    head->next = new node(9);
    head->next->next = new node(9);
    head->next->next->next = new node(8);

    node::addOneToLinkedList(head);

    while (head)
    {
        cout << head->data;
        head = head->next;
    }

    return 0;
}