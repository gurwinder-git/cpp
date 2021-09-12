#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x) : data(x), next(NULL){};
};

node *insertionSortList(node *head);

int main()
{

    // node n = 3;
    // node n(5);
    // int a(4);
    // cout << a << endl;
    // cout << n.data << endl;

    node *head = new node(5);
    // head->data = 1;
    head->next = new node(2);

    // head->next->data = 2;
    head->next->next = new node(10);

    // head->next->next->data = 3;
    head->next->next->next = new node(3);

    // head->next->next->next->data = 4;
    head->next->next->next->next = new node(4);

    // head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    head = insertionSortList(head);

    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }

    return 0;
}

node *insertionSortList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *mover = head;
    node *previousOfMover = head;
    node *compared = head->next;
    node *previousOfCompared = head;
    node *nextOfCompared = compared->next;

    while (compared)
    {
        while (mover != compared)
        {
            if (compared->data <= mover->data)
            {
                if (mover == head)
                {
                    head = compared;
                    compared->next = previousOfMover;
                    // previousOfCompared->next = nextOfCompared;
                }
                else
                {
                    previousOfMover->next = compared;
                    compared->next = mover;
                }
                previousOfCompared->next = nextOfCompared;
                break;
            }
            previousOfMover = mover;
            mover = mover->next;
        }
        if (mover == compared)
        {
            previousOfCompared = compared;
        }
        compared = nextOfCompared;
        if (nextOfCompared)
            nextOfCompared = nextOfCompared->next;
        else
            nextOfCompared = NULL;
        mover = head;
        previousOfMover = head;
    }
    return head;
}
