#include <iostream>
using namespace std;

void swapNumbersBypointes(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int &returningRefrence(int &a)
{
    return a;
}

int main()
{
    int x = 5, y = 7;
    cout << "x: " << x << " y: " << y << endl;
    swapNumbersBypointes(&x, &y);
    cout << "x: " << x << " y: " << y << endl;
    swapByReference(x, y);
    cout << "x: " << x << " y: " << y << endl;

    returningRefrence(x) = 2342;
    cout << "x: " << x << endl;

    return 1;
}