#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *rotateRight(struct node *head, int k);

int main()
{
    struct node n8;
    n8.data = 5;
    n8.next = NULL;

    struct node n7;
    n7.data = 4;
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

    struct node *result = rotateRight(head, 2);
    while (result)
    {
        cout << result->data << "  ";
        result = result->next;
    }

    return 0;
}

// optimal
node *rotateRight(node *head, int k)
{
    if (head == NULL)
        return head;
    int lenght = 1;

    node *tail = head;

    while (tail->next)
    {
        lenght++;
        tail = tail->next;
    }

    k = k % lenght;
    if (k == 0)
        return head;

    node *newHead = head;
    node *newTail = NULL;
    while (lenght > k)
    {
        newTail = newHead;
        newHead = newHead->next;

        lenght--;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

// brute force
//  struct node *rotateRight(struct node *head, int k)
//  {
//      if (head == NULL || head->next == NULL || k == 0)
//      {
//          return head;
//      }

//     struct node *previous = head;
//     struct node *tail = head;

//     //finding length of list
//     int len = 0;
//     struct node *temp_head = head;
//     while (temp_head != NULL)
//     {
//         len++;
//         temp_head = temp_head->next;
//     }

//     k = k % len;

//     while (k > 0)
//     {
//         while (tail->next != NULL)
//         {
//             previous = tail;
//             tail = tail->next;
//         }

//         tail->next = head;
//         previous->next = NULL;
//         head = tail;
//         previous = head;
//         k--;
//     }
//     return head;
// }