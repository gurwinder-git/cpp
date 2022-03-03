#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            ListNode *garbage = head;
            head = head->next;
            delete garbage;
        }

        ListNode *pre = head;
        ListNode *curr = head;

        while (curr)
        {
            if (curr->val == val)
            {
                while (curr && curr->val == val)
                {
                    curr = curr->next;
                }

                pre->next = curr;
            }
            pre = curr;
            curr = curr ? curr->next : curr;
        }

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    Solution sol;
    head = sol.removeElements(head, 6);

    while (head)
    {
        cout << head->val << "  ";
        head = head->next;
    }

    return 0;
}