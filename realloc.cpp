#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "How many numbers you want to store: ";
    cin >> n;

    int *memoryLocationPointer = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> *(memoryLocationPointer + i);
    }

    char userWantMoreNumbersToEnter;
    int newN;
    cout << endl
         << "Do you want more numbers to store? y/n: ";
    cin >> userWantMoreNumbersToEnter;

    if (userWantMoreNumbersToEnter == 'y' || userWantMoreNumbersToEnter == 'Y')
    {
        cout << "Enter how many numbers you want to store more: ";
        cin >> newN;
        memoryLocationPointer = (int *)realloc(memoryLocationPointer, ((newN + n) * sizeof(int)));

        for (int i = n; i < (n + newN); i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> *(memoryLocationPointer + i);
        }
    }
    cout << "You Entered" << endl;
    for (int i = 0; i < (n + newN); i++)
    {
        cout << *(memoryLocationPointer + i) << endl;
    }

    return 0;
}