#include <iostream>
using namespace std;

int closestEnemy(int arr[], int size)
{
    int distance = 0;
    int indexOfOne = -1;
    int indexOfEnemy = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            indexOfOne = i;
        }
        if (arr[i] > 1)
        {
            indexOfEnemy = i;
            break;
        }
    }

    distance = indexOfEnemy - indexOfOne;

    if (indexOfOne == -1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (arr[i] == 1)
            {
                indexOfOne = i;
            }
            if (arr[i] > 1)
            {
                indexOfEnemy = i;
                break;
            }
        }
    }

    if (indexOfOne > indexOfEnemy)
        distance = indexOfOne - indexOfEnemy;

    return distance;
}

int main()
{
    int arr[] = {0, 0, 1, 0, 0, 0, 2, 0};
    int a = closestEnemy(arr, 8);
    cout << a;

    return 0;
}