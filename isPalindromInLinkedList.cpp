#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL, *next = head;

        while (head)
        {
            next = head->next;

            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = this->reverseList(slow);

        while (head && head2)
        {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

    // O(n) space
    //   bool isPalindrome(ListNode *head)
    //  {
    //      stack<ListNode *> stk;
    //      ListNode *tempHead = head;

    //     while (tempHead)
    //     {
    //         stk.push(tempHead);
    //         tempHead = tempHead->next;
    //     }

    //     int mid = stk.size() / 2;

    //     while (mid--)
    //     {
    //         if (head->val != stk.top()->val)
    //             return false;
    //         head = head->next;
    //         stk.pop();
    //     }

    //     return true;
    // }

    // O(1) space
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    Solution sol;
    cout << sol.isPalindrome(head);

    return 0;
}