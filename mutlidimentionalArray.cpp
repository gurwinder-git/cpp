#include <iostream>
using namespace std;

int main()
{
    int cols, rows;
    cout << "rows, cols: ";
    cin >> rows >> cols;

    int **table = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        *(table + i) = new int[cols];
    }

    // *((*table) + 0) = 1;
    // *((*table) + 1) = 2;
    // *((*table) + 2) = 3;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cin >> (*((*table) + i)) + j;
            cin >> table[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cout << (*((*table) + i) + j) << "  ";
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[]((*table) + i);
    }

    delete[] table;
    table = NULL;

    return 0;
}