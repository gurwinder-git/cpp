#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *addTwoNumbers(struct node *l1, struct node *l2);

int main()
{
    struct node n3;
    n3.data = 0;
    n3.next = NULL;

    struct node n2;
    n2.data = 0;
    n2.next = &n3;

    struct node n1;
    n1.data = 9;
    n1.next = &n2;

    struct node *l1 = &n1;

    //2nd list

    struct node n7;
    n7.data = 9;
    n7.next = NULL;

    struct node n6;
    n6.data = 9;
    n6.next = &n7;

    struct node n5;
    n5.data = 3;
    n5.next = &n6;

    struct node n4;
    n4.data = 6;
    n4.next = &n5;

    struct node *l2 = &n4;

    struct node *l3_head = addTwoNumbers(l1, l2);

    while (l3_head)
    {
        cout << l3_head->data << "  ";
        l3_head = l3_head->next;
    }

    return 0;
}

struct node *addTwoNumbers(struct node *l1, struct node *l2)
{
    int addition = 0;
    int remander = 0;

    struct node *l3_head = (struct node *)malloc(sizeof(struct node));
    struct node *l3_tail = l3_head;
    struct node *prev_to_tail = NULL;

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            addition = l1->data;
            l1 = l1->next;
        };
        if (l2 != NULL)
        {
            addition = addition + l2->data;
            l2 = l2->next;
        };

        // cout << (addition + remander) % 10 << ',';

        if (l3_head == l3_tail)
        {
            l3_tail->data = ((addition + remander) % 10);
            l3_tail->next = NULL;
            prev_to_tail = l3_tail;
            l3_tail = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            l3_tail->data = ((addition + remander) % 10);
            l3_tail->next = NULL;
            prev_to_tail->next = l3_tail;
            prev_to_tail = l3_tail;
            l3_tail = (struct node *)malloc(sizeof(struct node));
        };

        remander = (addition + remander) / 10;
        addition = 0;
    };
    // cout << remander;
    if (remander > 0)
    {
        l3_tail->data = remander;
        l3_tail->next = NULL;
        prev_to_tail->next = l3_tail;
    };
    return l3_head;
}