#include <iostream>
using namespace std;

struct simple
{
    int c;
    int i;
    int t;
};

struct simple edit(struct simple obj)
{
    obj.c++;
    obj.i += 5;
    return obj;
}

void print(struct simple obj)
{
    cout << obj.c << endl;
    cout << obj.i << endl;
    cout << obj.t << endl;
}

int main()
{
    struct simple obj1 = {8, 1, 9};
    obj1 = edit(obj1);
    print(obj1);
    cout << sizeof(&obj1) << endl;
    cout << sizeof(obj1) << endl;
    cout << sizeof(-45) << endl;
    return 0;
}