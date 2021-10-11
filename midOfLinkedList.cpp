#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    static ListNode *midOfLinkedList(ListNode *head)
    {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(7);

    ListNode *resultHead = ListNode::midOfLinkedList(l1);

    while (resultHead)
    {
        cout << resultHead->data;
        resultHead = resultHead->next;
    }

    return 0;
}