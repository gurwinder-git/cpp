#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int count_nodes(struct node *head);

void traverse_linked_list(struct node *head);

void insert_node_at_end(struct node *head, int data);

struct node *insert_node_at_end_better_version(struct node *lastPtr, int data);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->next = NULL;

    head->next = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 30;
    current->next = NULL;

    head->next->next = current;

    // cout << head->data << endl;
    // cout << (*head).data << endl;
    // cout << head->next->data << endl;
    // cout << (*(*head).next).data << endl;
    // cout << head->next->next->data << endl;
    // cout << (*(*(*head).next).next).data << endl;
    // insert_node_at_end(head, 40);
    // insert_node_at_end(head, 50);
    // insert_node_at_end(head, 60);

    current = insert_node_at_end_better_version(current, 40);
    current = insert_node_at_end_better_version(current, 50);
    current = insert_node_at_end_better_version(current, 60);
    cout << "Number of nodes: " << count_nodes(head) << endl;
    traverse_linked_list(head);

    return 0;
}

int count_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        return count;

    struct node *ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = (*ptr).next;
        // ptr = ptr->next;
    }

    return count;
}

void traverse_linked_list(struct node *head)
{
    if (head == NULL)
        exit(0);

    struct node *ptr = head;

    while (ptr != NULL)
    {
        cout << (*ptr).data << endl;
        ptr = (*ptr).next;
    }
}

void insert_node_at_end(struct node *head, int data)
{
    if (head == NULL)
        exit(0);

    struct node *new_node_pointer = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    (*new_node_pointer).data = data;
    (*new_node_pointer).next = NULL;

    while ((*temp).next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node_pointer;
}

struct node *insert_node_at_end_better_version(struct node *lastPtr, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    lastPtr->next = new_node;
    return new_node;
}
