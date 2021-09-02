#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "How many Numbers you want to store: ";
    cin >> n;
    int *ptrToLocation = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "value: " << *(ptrToLocation + i) << endl;
        cout << "Enter number " << i + 1 << ": ";
        cin >> *(ptrToLocation + i);
    }

    cout << "Your Entered" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(ptrToLocation + i) << endl;
    }

    return 0;
}