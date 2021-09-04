#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *add_nodes(struct node *current, int data);
void display_linked_list(struct node *head);
struct node *reverse_linked_list(struct node *head);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    struct node *tail = head;

    tail = add_nodes(tail, 20);
    tail = add_nodes(tail, 30);
    tail = add_nodes(tail, 40);
    tail = add_nodes(tail, 50);
    tail = add_nodes(tail, 60);
    tail = add_nodes(tail, 70);
    head = reverse_linked_list(head);
    display_linked_list(head);

    return 0;
}

struct node *add_nodes(struct node *current, int data)
{
    struct node *ptr_to_new_node = (struct node *)malloc(sizeof(struct node));
    (*ptr_to_new_node).data = data;
    (*ptr_to_new_node).next = NULL;
    (*current).next = ptr_to_new_node;
    return ptr_to_new_node;
}

void display_linked_list(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

struct node *reverse_linked_list(struct node *head)
{
    struct node *prev_to_head, *next_to_head;
    prev_to_head = NULL;
    next_to_head = NULL;

    while (head != NULL)
    {
        next_to_head = (*head).next;
        (*head).next = prev_to_head;
        prev_to_head = head;
        head = next_to_head;
    }
    head = prev_to_head;
    return head;
}