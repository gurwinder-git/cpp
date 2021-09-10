#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *partionLinkedList(struct node *head, int k);

int main()
{
    node n8;
    n8.data = 1;
    n8.next = NULL;

    struct node n7;
    n7.data = 4;
    n7.next = &n8;

    struct node n6;
    n6.data = 3;
    n6.next = &n7;

    struct node n5;
    n5.data = 2;
    n5.next = &n6;

    struct node n4;
    n4.data = 1;
    n4.next = &n5;
    struct node *head = &n4;

    head = partionLinkedList(head, 3);
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    return 0;
}

struct node *partionLinkedList(struct node *head, int x)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *p1 = new node;
    node *p2 = new node;

    node *head1 = p1, *head2 = p2;

    while (head)
    {
        if (head->data < x)
        {
            p1->next = head;
            p1 = head;
        }
        else
        {
            p2->next = head;
            p2 = head;
        }
        head = head->next;
    }

    p2->next = NULL;
    p1->next = head2->next;

    return head1->next;
}
