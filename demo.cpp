#include <iostream>

using namespace std;

void fun(int *ptr)
{
    cout << *ptr << endl;
    *ptr = 20;
}

int main()
{
    int a = 10;
    int *ptr = &a;
    fun(ptr);
    cout << a;

    return 0;
}