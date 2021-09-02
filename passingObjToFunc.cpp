#include <iostream>

using namespace std;

struct charset
{
    char c;
    int i;
};

void takeInput(char *c, int *i)
{
    // cout << "c: " << c << endl;
    // cout << "i: " << i;
    cout << "Enter any char: ";
    cin >> *c;

    cout << "Enter any number: ";
    cin >> *i;
}

int main()
{
    struct charset cs1;

    takeInput(&(cs1.c), &(cs1.i));

    cout << "c: " << cs1.c << endl;
    cout << "i: " << cs1.i << endl;

    return 0;
}