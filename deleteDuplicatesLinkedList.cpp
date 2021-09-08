#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *deleteDuplicates(struct node *head);

int main()
{
    struct node n8;
    n8.data = 3;
    n8.next = NULL;

    struct node n7;
    n7.data = 3;
    n7.next = &n8;

    struct node n6;
    n6.data = 2;
    n6.next = &n7;

    struct node n5;
    n5.data = 1;
    n5.next = &n6;

    struct node n4;
    n4.data = 1;
    n4.next = &n5;
    struct node *head = &n4;

    head = deleteDuplicates(head);
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }

    return 0;
}

struct node *deleteDuplicates(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *previous_ptr = head;
    struct node *next_ptr = head->next;

    while (previous_ptr->next != NULL)
    {
        if ((*previous_ptr).data == (*next_ptr).data)
        {
            previous_ptr->next = next_ptr->next;
            next_ptr->next = NULL;
            next_ptr = previous_ptr->next;
        }
        else
        {
            next_ptr = next_ptr->next;
            previous_ptr = previous_ptr->next;
        }
    }
    return head;
}