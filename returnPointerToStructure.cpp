#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
};

struct point *getPointer(int a, int b)
{
    struct point *ptr = (struct point *)calloc(1, sizeof(struct point));
    (*ptr).x = a;
    ptr->x = a;
    (*ptr).y = b;
    ptr->y = b;

    return ptr;
}

void printUsingPointer(struct point *p)
{
    cout << "Data In Heap memory: " << endl;
    cout << p->x << endl;
    cout << p->y << endl;
}

int main()
{
    struct point *p1;
    p1 = getPointer(4, 6);
    printUsingPointer(p1);
    free(p1);
    p1 = NULL;

    // cout << sizeof(struct point);

    return 0;
}