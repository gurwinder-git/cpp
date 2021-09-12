#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x) : data(x), next(NULL){};
};

node *getIntersectionNode(node *headA, node *headB);

int main()
{

    // node n = 3;
    // node n(5);
    // int a(4);
    // cout << a << endl;
    // cout << n.data << endl;

    node *headA = new node(5);
    // head->data = 1;
    headA->next = new node(2);

    // headA->next->data = 2;
    headA->next->next = new node(10);

    // headA->next->next->data = 3;
    headA->next->next->next = new node(3);

    // headA->next->next->next->data = 4;
    headA->next->next->next->next = new node(4);

    // headA->next->next->next->next->data = 5;
    headA->next->next->next->next->next = NULL;

    node *headB = new node(1);
    headB->next = new node(3);
    headB->next->next = headA->next->next->next;

    node *i = getIntersectionNode(headA, headB);
    if (i)
        cout << "intersection At: " << i->data;
    else
        cout << "NO intersection";

    return 0;
}

node *getIntersectionNode(node *headA, node *headB)
{
    if (!headA || !headB)
    {
        return NULL;
    }

    node *tempA = headA;
    node *tempB = headB;

    while (tempA != tempB)
    {
        if (tempA == NULL)
            tempA = headB;
        else
            tempA = tempA->next;

        if (tempB == NULL)
            tempB = headA;
        else
            tempB = tempB->next;
    }

    return tempA;
}