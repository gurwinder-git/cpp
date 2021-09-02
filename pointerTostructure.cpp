#include <iostream>
using namespace std;

struct simple
{
    int c;
    int i;
    int t;
    int y;
};

void printObj(struct simple *obj)
{
    cout << "Data in object" << endl;
    cout << "C: " << (obj->c);
    cout << endl;
    // *obj = all addresses
    // i = valueof i
    cout << "I: " << (*obj).i;
    cout << endl;

    cout << "sizeof(*obj): " << sizeof(*obj);
    cout << endl;
    cout << "sizeof(obj): " << sizeof(obj);
    cout << endl;
}

int main()
{
    struct simple obj1 = {8, 1, 9, 8};
    printObj(&obj1);
    return 0;
}