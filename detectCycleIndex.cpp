#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x) : data(x), next(NULL){};
};

node *detectCycleIndex(node *head);

int main()
{

    // node n = 3;
    // node n(5);
    // int a(4);
    // cout << a << endl;
    // cout << n.data << endl;

    node *head = new node(1);
    // head->data = 1;
    head->next = new node(2);

    // head->next->data = 2;
    head->next->next = new node(3);

    // head->next->next->data = 3;
    head->next->next->next = new node(4);

    // head->next->next->next->data = 4;
    head->next->next->next->next = new node(5);

    // head->next->next->next->next->data = 5;
    head->next->next->next->next->next = head->next->next;

    node *loop = detectCycleIndex(head);
    int i = 0;
    while (head)
    {
        if (head == loop)
        {
            cout << "cycle at index " << i;
            break;
        }
        if (loop == NULL)
        {
            cout << "NO cycle";
            break;
        }
        head = head->next;
        i++;
    }

    return 0;
}

node *detectCycleIndex(node *head)
{
    if (!head)
        return head;

    node *slow = head, *fast = head, *index = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }

    if (!fast || !(fast->next))
        return NULL;

    while (index != slow)
    {
        index = index->next;
        slow = slow->next;
    }

    return index;
}