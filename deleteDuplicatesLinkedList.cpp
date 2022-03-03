#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head);

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *pre = head;
        ListNode *curr = head->next;

        while (curr)
        {
            while (curr && curr->val == pre->val)
            {
                curr = curr->next;
            }

            pre->next = curr;
            pre = curr;
            curr = curr ? curr->next : curr;
        }

        return head;
    }
};
int main()
{
    struct ListNode n8;
    n8.val = 3;
    n8.next = NULL;

    struct ListNode n7;
    n7.val = 3;
    n7.next = &n8;

    struct ListNode n6;
    n6.val = 2;
    n6.next = &n7;

    struct ListNode n5;
    n5.val = 1;
    n5.next = &n6;

    struct ListNode n4;
    n4.val = 1;
    n4.next = &n5;
    struct ListNode *head = &n4;

    Solution sol;
    head = sol.deleteDuplicates(head);
    while (head)
    {
        cout << head->val << "  ";
        head = head->next;
    }

    return 0;
}

// struct ListNode *deleteDuplicates(struct ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     struct ListNode *previous_ptr = head;
//     struct ListNode *next_ptr = head->next;

//     while (previous_ptr->next != NULL)
//     {
//         if ((*previous_ptr).val == (*next_ptr).val)
//         {
//             previous_ptr->next = next_ptr->next;
//             next_ptr->next = NULL;
//             next_ptr = previous_ptr->next;
//         }
//         else
//         {
//             next_ptr = next_ptr->next;
//             previous_ptr = previous_ptr->next;
//         }
//     }
//     return head;
// }