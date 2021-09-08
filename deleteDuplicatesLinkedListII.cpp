#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *delete_duplicate(struct node *head);

int main()
{
    struct node n9;
    n9.data = 6;
    n9.next = NULL;

    struct node n8;
    n8.data = 5;
    n8.next = &n9;

    struct node n7;
    n7.data = 3;
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

    head = delete_duplicate(head);
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    return 0;
}

struct node *delete_duplicate(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct node *result_head = NULL;
    struct node *updater = head;
    struct node *current = head;
    struct node *next_to_current = head->next;

    int previous_value = -101;
    int current_value = current->data;
    int next_value = next_to_current->data;

    while (current != NULL)
    {
        if (current_value != previous_value && current_value != next_value)
        {
            if (result_head == NULL)
            {
                result_head = current;
            }

            updater = current;
            current = current->next;
            if (next_to_current)
                next_to_current = next_to_current->next;
            else
                next_to_current = NULL;
        }
        else
        {
            updater->next = current->next;
            current = current->next;
            if (next_to_current)
                next_to_current = next_to_current->next;
            else
                next_to_current = NULL;
        }

        previous_value = current_value;

        if (current)
            current_value = current->data;
        else
            current_value = -101;

        if (next_to_current)
            next_value = next_to_current->data;
        else
            next_value = -101;
    }
    return result_head;
}