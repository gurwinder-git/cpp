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

    node n13;
    n13.data = 13;
    n13.next = NULL;

    node n12;
    n12.data = 12;
    n12.next = &n13;

    node n11;
    n11.data = 11;
    n11.next = &n12;

    node n10;
    n10.data = 10;
    n10.next = &n11;

    node n9;
    n9.data = 9;
    n9.next = &n10;

    node n8;
    n8.data = 7;
    n8.next = &n9;

    struct node n7;
    n7.data = 8;
    n7.next = &n8;

    struct node n6;
    n6.data = 5;
    n6.next = &n7;

    struct node n5;
    n5.data = 4;
    n5.next = &n6;

    struct node n4;
    n4.data = 3;
    n4.next = &n5;
    struct node *head = &n4;

    head = reverseBetween(head, 1, 10);
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    return 0;
}

struct node *reverseBetween(node *head, int left, int right)
{
    if (!head || (left >= right) || (left <= 0))
        return head;

    int totalNodes = 0;
    node *tempHead = head;
    while (tempHead)
    {
        tempHead = tempHead->next;
        totalNodes++;
    }

    if (right > totalNodes)
        return head;

    node *previousToHead = NULL;
    tempHead = head;
    node *nextToHead = NULL;

    int counter = 1;

    while (counter < right)
    {
        if (counter >= left && counter <= right)
        {
            nextToHead = tempHead->next;
            tempHead->next = previousToHead;
            previousToHead = tempHead;
            tempHead = nextToHead;
        }
        else
        {
            tempHead = tempHead->next;
        }
        counter++;
    }

    // node *tailOfFirstPortion = NULL;
    if (left == 1)
    {
        head = tempHead;
        nextToHead = nextToHead->next;
        tempHead->next = previousToHead;

        node *tailAddress;

        if (tempHead->next == NULL)
        {
            tailAddress = tempHead;
        }
        else
        {
            while (tempHead->next != NULL)
            {
                tailAddress = tempHead;
                tempHead = tempHead->next;
            }
        }

        tailAddress->next = nextToHead;
        return head;
    }

    if (left > 1)
    {
        tempHead = head;
        node *tailAddress = NULL;
        if (tempHead->next == NULL)
        {
            tailAddress = tempHead;
        }
        else
        {
            while (tempHead->next != NULL)
            {
                tailAddress = tempHead;
                tempHead = tempHead->next;
            }
        }

        tempHead = nextToHead;
        nextToHead = nextToHead->next;
        tailAddress->next = tempHead;
        tempHead->next = previousToHead;
        ////////

        tempHead = head;
        if (tempHead->next == NULL)
        {
            tailAddress = tempHead;
        }
        else
        {
            while (tempHead->next != NULL)
            {
                tailAddress = tempHead;
                tempHead = tempHead->next;
            }
        }

        tailAddress->next->next = nextToHead;
    }

    return head;
}