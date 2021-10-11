#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    static bool isPalindrome(node *head)
    {
        stack<node *> stk;
        node *tempHead = head;

        while (tempHead)
        {
            stk.push(tempHead);
            tempHead = tempHead->next;
        }

        int mid = stk.size() / 2;

        while (mid--)
        {
            if (head->data != stk.top()->data)
                return false;
            head = head->next;
            stk.pop();
        }

        return true;
    }
};

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(2);
    head->next->next->next = new node(1);

    cout << node::isPalindrome(head);

    return 0;
}