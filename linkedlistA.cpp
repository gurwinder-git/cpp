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
struct node *insert_at_beginning(struct node *head, int data);
void insert_at_beginning_another_way(struct node **ptrToHead, int data);
void insert_at_certion_position(struct node *head, int data, int position);
struct node *delete_first_node(struct node *head);
void delete_last_node(struct node *head);
void delete_note_from_certain_position(struct node **ptrToHead, int position);

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
    // head = insert_at_beginning(head, 4);
    // head = insert_at_beginning(head, 3);
    // head = insert_at_beginning(head, 2);
    // head = insert_at_beginning(head, 1);
    // insert_at_beginning_another_way(&head, 0);
    // insert_at_certion_position(head, 3242, 5);
    // head = delete_first_node(head);
    // delete_last_node(head);
    // delete_last_node(head);
    // delete_note_from_certain_position(&head, 1);
    // delete_note_from_certain_position(&head, 2);
    // delete_note_from_certain_position(&head, 3);
    // delete_note_from_certain_position(&head, 5);
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

struct node *insert_at_beginning(struct node *head, int data)
{
    struct node *ptr_to_new_node = (struct node *)malloc(sizeof(struct node));
    ptr_to_new_node->data = data;
    ptr_to_new_node->next = head;

    return ptr_to_new_node;
}

void insert_at_beginning_another_way(struct node **ptrToHead, int data)
{
    struct node *ptr_to_new_node = (struct node *)malloc(sizeof(struct node));
    (*ptr_to_new_node).data = data;
    (*ptr_to_new_node).next = *ptrToHead;

    *ptrToHead = ptr_to_new_node;
    // cout << endl
    //      << *ptrToHead;
}

void insert_at_certion_position(struct node *head, int data, int position)
{
    struct node *ptr_to_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    // ((struct node *)ptr_to_node)->data = data;
    ptr_to_node->data = data;

    while (position != 2)
    {
        ptr = (*ptr).next;
        // ptr = ptr->next;
        position--;
    }

    ptr_to_node->next = ptr->next;
    // (*ptr_to_node).next = (*ptr).next;
    (*ptr).next = ptr_to_node;
}

struct node *delete_first_node(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
        exit(1);

    head = (*head).next;
    free(temp);
    temp = NULL;
    return head;
}

void delete_last_node(struct node *head)
{
    struct node *lastPtr, *secLastNodePtr;
    lastPtr = secLastNodePtr = head;

    while (lastPtr->next != NULL)
    {
        secLastNodePtr = lastPtr;
        lastPtr = lastPtr->next;
    }

    secLastNodePtr->next = NULL;
    free(lastPtr);
    lastPtr = NULL;
}

void delete_note_from_certain_position(struct node **ptrToHead, int position)
{
    if (*ptrToHead == NULL)
        exit(0);

    else if (position == 1)
    {
        struct node *temp = *ptrToHead;
        *ptrToHead = (*(*ptrToHead)).next;
        // *ptrToHead = (*ptrToHead)->next;
        free(temp);
    }
    else
    {
        struct node *current = *ptrToHead, *previous = *ptrToHead;

        while (position != 1)
        {
            previous = current;
            current = (*current).next;
            position--;
        }

        previous->next = current->next;
        free(current);
        current = NULL;
    }
}