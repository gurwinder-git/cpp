#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x) : data(x), next(NULL){};
};

node *reorderList(node *head);

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
    head->next->next->next->next->next = NULL;

    head = reorderList(head);

    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }

    return 0;
}

node *reorderList(node *head)
{
    if (!head || !(head->next))
        return head;

    node *headTemp = head;
    node *nextToHead = head->next;
    node *tail = head;
    node *previousToTail = tail;

    while (nextToHead)
    {
        while (tail->next != NULL)
        {
            previousToTail = tail;
            tail = tail->next;
        }
        if (nextToHead == tail)
            break;

        //updating nodes
        headTemp->next = tail;
        tail->next = nextToHead;
        previousToTail->next = NULL;

        //udating temp pointers
        headTemp = nextToHead;
        tail = nextToHead;
        previousToTail = nextToHead;
        nextToHead = nextToHead->next;
        }

    // cout << previousToTail->data << "  ";
    // cout << tail->data << "  ";
    return head;
}