#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *removeNthFromEnd(struct node *head, int n);

int main()
{
    struct node n8;
    n8.data = 2;
    n8.next = NULL;

    struct node n7;
    n7.data = 4;
    n7.next = &n8;

    struct node n6;
    n6.data = 6;
    n6.next = &n7;

    struct node n5;
    n5.data = 8;
    n5.next = &n6;

    struct node n4;
    n4.data = 6;
    n4.next = &n5;

    struct node *head = &n4;

    head = removeNthFromEnd(head, 1);
    cout << "output" << endl;
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}

struct node *removeNthFromEnd(struct node *head, int n)
{
    if (head == NULL)
    {
        return head;
    }

    struct node *head_ptr = head;
    int total_nodes = 0;

    while (head_ptr)
    {
        total_nodes++;
        head_ptr = (*head_ptr).next;
    }

    int nthNodeFromStart = (total_nodes - n) + 1;

    if (nthNodeFromStart == 1)
    {
        struct node *second_node_ptr = head->next;
        free(head);
        return second_node_ptr;
    }

    if (nthNodeFromStart > 1 && nthNodeFromStart <= total_nodes)
    {
        struct node *previous, *current;
        previous = current = head;

        while (nthNodeFromStart != 1)
        {
            previous = current;
            current = (*current).next;

            nthNodeFromStart--;
        }

        (*previous).next = (*current).next;
        free(current);
        return head;
    }
    return head;
}