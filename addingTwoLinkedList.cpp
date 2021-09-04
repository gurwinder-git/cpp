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
    n3.data = 4;
    n3.next = NULL;

    struct node n2;
    n2.data = 3;
    n2.next = &n3;

    struct node n1;
    n1.data = 5;
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
    n5.data = 8;
    n5.next = &n6;

    struct node n4;
    n4.data = 6;
    n4.next = &n5;

    struct node *l2 = &n4;

    addTwoNumbers(l1, l2);

    return 0;
}

struct node *addTwoNumbers(struct node *l1, struct node *l2)
{
    int addition = 0;
    int remander = 0;

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            addition = l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            addition = addition + l2->data;
            l2 = l2->next;
        }

        cout << (addition + remander) % 10 << ',';

        remander = (addition + remander) / 10;
        addition = 0;
    }
    cout << remander;
}