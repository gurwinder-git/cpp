#include <iostream>

using namespace std;

class Solution
{
public:
    void selectionSort(int arr[], int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int minValIndex = start;

        for (int i = minValIndex + 1; i <= end; i++)
        {
            if (arr[i] < arr[minValIndex])
                minValIndex = i;
        }

        // swap
        int temp = arr[minValIndex];
        arr[minValIndex] = arr[start];
        arr[start] = temp;

        selectionSort(arr, start + 1, end);
    }
};

int main()
{
    int arr[] = {5, 3, 2, 4, 6, 3, 2, 0, 97, 6, 35, 757, 86, 2, 56, 76, 465};

    Solution sol;

    int n = sizeof(arr) / sizeof(int);

    sol.selectionSort(arr, 0, n - 1);
    // cout<<sizeof(arr)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}