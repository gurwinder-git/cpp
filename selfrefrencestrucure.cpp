#include <iostream>
using namespace std;

struct self
{
    int a;
    int b;
    struct self *ptr;
};

int main()
{
    struct self n1 = {12, 14, NULL};
    struct self n2 = {42, 13, NULL};
    n1.ptr = &n2;

    cout << "n2.a: " << (*n1.ptr).a << endl
         << "n2.b: " << n1.ptr->b;

    return 0;
}