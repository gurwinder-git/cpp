#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

bool hasCycle(struct node *head);

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

    // node n9;
    // n9.data = 8;
    // n9.next = &n10;

    node *head = new node;
    // head->data = 1;
    // head->next = new node;
    // head->next = NULL;

    head->next->data = 2;
    head->next->next = new node;

    head->next->next->data = 3;
    head->next->next->next = new node;

    head->next->next->next->data = 4;
    head->next->next->next->next = new node;

    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = head->next->next;
    // head->next->next->next->next->next = NULL;

    //

    cout << hasCycle(head);
    return 0;
}

bool hasCycle(struct node *head)
{
    if (head == NULL)
        return false;

    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
        if (slow == NULL && fast == NULL)
            return false;
        if (slow == fast)
            return true;
    } while (fast);

    return fast;
}