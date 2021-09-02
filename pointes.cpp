#include <iostream>
using namespace std;

int main()
{

    // variables are only representation of address of values

    int a = 10;
    int *p = &a;
    // int *p = addressof(a);

    cout << "addressof(a): " << addressof(a) << endl;
    cout << "&a:           " << &a << endl;
    cout << "*p:           " << p << endl;

    cout << "--------------" << endl;

    int **pop = &p;

    cout << "addressof(p): " << addressof(p) << endl;
    cout << "&p:           " << &p << endl;
    cout << "**pop:        " << pop << endl;

    cout << "----------------" << endl;
    cout << "derefrencing operator * " << endl;
    cout << endl;

    cout << "value of 'a':   " << *p << endl;
    cout << "value of 'pop': " << *pop << endl; //0x61ff08
    cout << "value of 'a':   " << **pop << endl;

    cout << "--------- Array with pointers---------" << endl;

    int arr[] = {112, 234, 365, 476, 589};

    int *pointer_of_array = arr;

    // cout << "array output with pointers: " << endl;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "address of "
    //          << "arr[" << i << "] " << pointer_of_array + i << endl;
    //     cout << "value of "
    //          << "arr[" << i << "] " << *(pointer_of_array + i) << endl
    //          << endl;
    // }

    return 0;
}