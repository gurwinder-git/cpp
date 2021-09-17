#include <iostream>
using namespace std;

int func(int (*funcptr)(int, int), int a, int b)
{
    return funcptr(a, b);
}

int add(int a, int b)
{
    return a + b;
}
int main()
{

    cout << func(add, 6, 7);

    return 0;
}