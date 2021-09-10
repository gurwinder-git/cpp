#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *reverseBetween(struct node *head, int left, int right);

int main()
{

    // node n13;
    // n13.data = 13;
    // n13.next = NULL;

    // node n12;
    // n12.data = 12;
    // n12.next = &n13;

    // node n11;
    // n11.data = 11;
    // n11.next = &n12;

    // node n10;
    // n10.data = 10;
    // n10.next = &n11;

    node n9;
    n9.data = 8;
    n9.next = NULL;

    node n8;
    n8.data = 7;
    n8.next = &n9;

    struct node n7;
    n7.data = 5;
    n7.next = &n8;

    struct node n6;
    n6.data = 3;
    n6.next = &n7;

    struct node n5;
    n5.data = 4;
    n5.next = &n6;

    struct node n4;
    n4.data = 7;
    n4.next = &n5;
    struct node *head = &n4;

    head = reverseBetween(head, 1, 6);
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    return 0;
}

struct node *reverseBetween(node *head, int left, int right)
{
    node *partion_1_tail = NULL;
    node *partion_2_head = NULL;

    node *previous = NULL;
    node *current = head;
    node *next_to_current = NULL;

    node *reversed_list_tail = NULL;
    node *reversed_list_head = NULL;

    node *current_traversal = head;

    int counter = 1;
    while (counter <= right)
    {

        if (counter + 1 == left)
        {
            partion_1_tail = current_traversal;
        }

        if (counter == left)
        {
            reversed_list_tail = current_traversal;
        }

        if (counter == right)
        {
            reversed_list_head = current_traversal;
            partion_2_head = current_traversal->next;
        }

        if (counter >= left && counter <= right)
        {
            next_to_current = current->next;
            current->next = previous;
            previous = current;
            current = next_to_current;
        }
        else
        {
            current = current->next;
        }

        // current_traversal = next_to_current;
        current_traversal = current;
        counter++;
    }

    if (partion_2_head)
        reversed_list_tail->next = partion_2_head;

    if (partion_1_tail)
        partion_1_tail->next = reversed_list_head;
    else
        head = reversed_list_head;

    return head;
}