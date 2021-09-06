#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *swapPairs(struct node *head);

int main()
{
    struct node n7;
    n7.data = 7;
    n7.next = NULL;

    struct node n6;
    n6.data = 6;
    n6.next = &n7;

    struct node n5;
    n5.data = 5;
    n5.next = &n6;

    struct node n4;
    n4.data = 4;
    n4.next = &n5;

    struct node n3;
    n3.data = 3;
    n3.next = &n4;

    struct node n2;
    n2.data = 2;
    n2.next = &n3;

    struct node n1;
    n1.data = 1;
    n1.next = &n2;

    struct node *head = &n1;

    head = swapPairs(head);
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}

struct node *swapPairs(struct node *head)
{
    if (head == NULL || (*head).next == NULL)
    {
        return head;
    }

    struct node *previous_ptr = head;
    struct node *middle_ptr = head->next;
    struct node *next_ptr = middle_ptr->next;

    struct node *result_head_ptr = middle_ptr;

    while (middle_ptr != NULL)
    {
        //updating nodes
        middle_ptr->next = previous_ptr;

        if (next_ptr == NULL)
        {
            previous_ptr->next = next_ptr;
        }
        else if (next_ptr->next != NULL)
        {
            previous_ptr->next = next_ptr->next;
        }

        else
        {
            previous_ptr->next = next_ptr;
        }

        //updating temp pointers
        previous_ptr = next_ptr;
        ///////////////////////
        if (next_ptr)
            middle_ptr = next_ptr->next;
        else
            middle_ptr = next_ptr;
        /////////////
        if (next_ptr)
        {
            if (next_ptr->next)
                next_ptr = next_ptr->next->next;
            else
                next_ptr = NULL;
        }
        else
        {
            next_ptr = NULL;
        }
    }

    return result_head_ptr;
}