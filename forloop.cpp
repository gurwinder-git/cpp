#include <iostream>

using namespace std;

bool verify(int i)
{
    cout << "v" << i << endl;
    return i < 10;
}
int main()
{
    int i = 0;
    for (i; i < 10; i++)
    {
        cout << i << endl;
        i = i + 2;
    }
    cout << i;

    return 0;
}