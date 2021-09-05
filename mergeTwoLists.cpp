#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *mergeTwoLists(struct node *l1, struct node *l2);
struct node *construct_sorted_list(struct node **ptr_to_head, struct node *tail, int data);

int main()
{
    struct node n3;
    n3.data = 9;
    n3.next = NULL;

    struct node n2;
    n2.data = 6;
    n2.next = &n3;

    struct node n1;
    n1.data = 3;
    n1.next = &n2;

    struct node *l1 = &n1;

    //2nd list

    struct node n8;
    n8.data = 10;
    n8.next = NULL;

    struct node n7;
    n7.data = 6;
    n7.next = &n8;

    struct node n6;
    n6.data = 4;
    n6.next = &n7;

    struct node n5;
    n5.data = 3;
    n5.next = &n6;

    struct node n4;
    n4.data = 3;
    n4.next = &n5;
    struct node *l2 = &n4;
    struct node *result = mergeTwoLists(l1, l2);
    while (result)
    {
        cout << result->data << endl;
        result = result->next;
    }

    return 0;
}

struct node *mergeTwoLists(struct node *l1, struct node *l2)
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int number;
    while (l1 && l2)
    {
        if (l1->data <= l2->data)
        {
            number = l1->data;
            tail = construct_sorted_list(&head, tail, number);
            l1 = l1->next;
        }
        else
        {
            number = l2->data;
            tail = construct_sorted_list(&head, tail, number);
            l2 = l2->next;
        }
        // cout << number << endl;
    }
    while (l1)
    {
        number = l1->data;
        tail = construct_sorted_list(&head, tail, number);
        l1 = l1->next;
        // cout << number << endl;
    }
    while (l2)
    {
        number = l2->data;
        tail = construct_sorted_list(&head, tail, number);
        l2 = l2->next;
        // cout << number << endl;
    }
    return head;
}

struct node *construct_sorted_list(struct node **ptr_to_head, struct node *tail, int data)
{
    if (*ptr_to_head == NULL)
    {
        *ptr_to_head = (struct node *)malloc(sizeof(struct node));
        (*(*ptr_to_head)).data = data;
        (*(*ptr_to_head)).next = NULL;
        return *ptr_to_head;
    }
    else
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        (*tail).next = new_node;
        return new_node;
    }
}