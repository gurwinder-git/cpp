#include <iostream>

using namespace std;

int main()
{
    int i;
    float f;
    double d;
    long double ld;
    unsigned int ui;
    signed int si;
    bool b;
    char c;
    short int shi;
    long int loi;

    // cout << "size of int: " << sizeof(i) << endl;
    // cout << "size of float: " << sizeof(f) << endl;
    // cout << "size of double: " << sizeof(d) << endl;
    // cout << "size of long double: " << sizeof(ld) << endl;
    // cout << "size of unsigned int: " << sizeof(ui) << endl;
    // cout << "size of signed int: " << sizeof(si) << endl;
    // cout << "size of bool: " << sizeof(b) << endl;
    // cout << "size of char: " << sizeof(c) << endl;
    // cout << "size of short int: " << sizeof(shi) << endl;
    // cout << "size of long int: " << sizeof(loi) << endl;

    int x = 100;
    int &y = x;

    cout << y << endl;
    cout << &x << endl;

    cout << "size of address: " << sizeof(y);

    return 0;
}