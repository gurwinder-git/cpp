#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

//type is need to determine which type of data is there and also for arthmetic operations
int main()
{
    struct node *head = NULL;

    //       type
    head = (struct node *)malloc(2 * sizeof(struct node));

    (*head).data = 10;
    (*head).link = NULL;

    cout << "data: " << head->data << endl;
    cout << "link: " << head->link << endl;

    (*(head + 1)).data = 12;
    (*(head + 1)).link = NULL;

    cout << "data: " << (head + 1)->data << endl;
    cout << "link: " << (head + 1)->link << endl;

    cout << "precticing" << '\n';
    struct node n1 = {23, NULL};
    head = &n1;
    (*head).data = 10;

    return 0;
}