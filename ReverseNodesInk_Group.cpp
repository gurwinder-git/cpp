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
    ListNode *oh, *ot, *th, *tt;

    void addFirst(ListNode *&node)
    {
        if (this->th == NULL && this->tt == NULL)
        {
            this->th = this->tt = node;
        }
        else
        {
            node->next = this->th;
            this->th = node;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        this->oh = this->ot = new ListNode(-1);
        this->th = this->tt = NULL;

        int size = 0;

        ListNode *curr = head, *next;
        while (curr)
        {
            size++;
            curr = curr->next;
        }

        curr = head;

        while (true)
        {
            if (size >= k)
            {
                for (int i = 0; i < k; i++)
                {
                    next = curr->next;
                    curr->next = NULL;

                    addFirst(curr);
                    curr = next;
                }

                this->ot->next = this->th;
                this->ot = this->tt;

                this->th = this->tt = NULL;
            }
            else
            {
                this->ot->next = curr;
                break;
            }

            size -= k;
        }

        return this->oh->next;
    }
};

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    Solution sol;

    head = sol.reverseKGroup(head, 4);

    while (head)
    {
        cout << head->val << "  ";
        head = head->next;
    }

    return 0;
}