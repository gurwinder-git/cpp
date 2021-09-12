#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x) : data(x), next(NULL){};
};

node *oddEvenList(node *head);

int main()
{

    // node n = 3;
    // node n(5);
    // int a(4);
    // cout << a << endl;
    // cout << n.data << endl;

    node *head = new node(1);
    // head->data = 1;
    head->next = new node(2);

    // head->next->data = 2;
    head->next->next = new node(3);

    // head->next->next->data = 3;
    head->next->next->next = new node(4);

    // head->next->next->next->data = 4;
    head->next->next->next->next = new node(5);

    // head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    head = oddEvenList(head);

    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }

    return 0;
}

node *oddEvenList(node *head)
{
    if (!head || !(head->next) || !(head->next->next))
        return head;

    node *oddTail = head;
    node *evenHead = head->next;
    node *evenTail = evenHead;
    node *previousOfOddTail = oddTail;

    while (oddTail && evenTail)
    {
        if (oddTail && oddTail->next)
        {
            oddTail->next = evenTail->next;
            previousOfOddTail = oddTail;
            oddTail = oddTail->next;
        }

        if (evenTail && evenTail->next)
        {
            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }
    }

    if (oddTail)
        oddTail->next = evenHead;
    else
        previousOfOddTail->next = evenHead;

    return head;
}