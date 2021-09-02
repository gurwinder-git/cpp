#include <iostream>
using namespace std;

struct simple
{
    char c;
    int i;
};

void printObj(struct simple s)
{
    cout << "Data in object" << endl;
    cout << "c: " << s.c << " I: " << s.i << endl;
}

int main()
{
    struct simple obj1 = {'u', 1};
    printObj(obj1);
    printObj({'4', 5});
    struct simple obj3 = obj1;

    return 0;
}