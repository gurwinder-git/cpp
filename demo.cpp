#include <iostream>

using namespace std;

struct node
{
    int a;
    int b;
};

// void fun(int **ptr)
// {
//     cout << *ptr << endl;
//     int *np = (int *)malloc(4);
//     **ptr = 50;
//     *ptr = np;
//     **ptr = 5656;
// }

// int main()
// {
//     int a = 10;
//     int *ptr = &a;
//     fun(&ptr);
//     cout << *ptr << "\n";
//     cout << a;

//     return 0;
// }

// struct node
// {
//     int a;
//     int b;
// };

// int main()
// {
//     struct node n1;
//     int *ptr = &(n1.a);
//     *ptr = 10;
//     cout << n1.a << endl;
//     cout << *ptr << endl;

//     return 0;
// }

// int main()
// {
//     struct node ns[] = {{12, 32}, {45, 56}};
//     struct node *ptr = ns;
//     int *p = &(ptr->a);
//     *p = 2352352;
//     cout << ptr->a << endl;
//     cout << ptr->b << endl;
//     ptr++;
//     cout << ptr->a << endl;
//     cout << ptr->b << endl;

//     return 0;
// }

// int main()
// {
//     int *p = (int *)malloc(4);
//     *p = 104;
//     *(p + 1) = 232;
//     cout << *p << endl;
//     cout << *++p << endl;
//     return 0;
// }

// int main()
// {
//     struct node *p = (struct node *)malloc(1);
//     p->a = 10;
//     p->b = 34;

//     (*(p + 1)).a = 23;
//     (p + 1)->b = 265;
//     cout << p->a << endl;
//     cout << p->b << endl;
//     cout << (p + 1)->a << endl;
//     cout << (p + 1)->b << endl;

//     return 0;
// }

// int main()
// {
//     int *arr = new int[2];
//     *(arr) = 12;
//     *(arr + 1) = 45;
//     arr[2] = 44;
//     cout << *arr << endl;
//     cout << *(arr + 1) << endl;
//     cout << *(arr + 2) << endl;

//     int arr2[2] = {12, 334};
//     arr2[0] = 0;
//     arr2[1] = 0;
//     arr2[2] = 0;
//     arr2[3] = 0;
//     arr2[4] = 0;
//     cout << arr2[0] << endl;
//     cout << arr2[1] << endl;
//     cout << arr2[2] << endl;
//     cout << arr2[3] << endl;
//     cout << arr2[4] << endl;

//     return 0;
// }

int main()
{
    // string s1({'a', 'b', 'b', 'a'}); //static
    string s1 = {'a', 'b', 'b', 'a'};              //static
    string *s2 = new string({'a', 'b', 'b', 'a'}); //dynamic
    cout << s2->length() << endl;
    // getline(cin, s1);
    s1[1] = 'e';

    char *ptr = new char[10]{'d', 'f', 't', 'i', '\0'};

    int i = 0;
    while (ptr[i])
    {
        cout << ptr[i];
        i++;
    }
    // char *ptr1 = "df";
    ptr[0] = 'y';

    cout << ptr[0] << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr) << endl;
    cout << ptr << endl;
    int *p = new int(3);
    return 0;
}