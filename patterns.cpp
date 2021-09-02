#include <iostream>

using namespace std;

int main()
{
    /*problem*/
    // *
    // **
    // ***
    // ****
    // *****

    // for (int y = 0; y < 5; y++)
    // {
    //     for (int x = 0; x <= y; x++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    /*problem*/
    // *****
    // ****
    // ***
    // **
    // *

    // for (int y = 0; y < 5; y++)
    // {
    //     for (int x = 0; x < 5 - y; x++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    /*problem*/
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5

    // for (int y = 0; y < 5; y++)
    // {
    //     for (int x = 0; x <= y; x++)
    //     {
    //         cout << x + 1;
    //     }

    //     cout << endl;
    // }

    /*problem*/
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    // int rows = 5;

    // for (int y = rows; y > -1; y--)
    // {
    //     for (int x = 0; x < y; x++)
    //     {
    //         cout << x + 1;
    //     }
    //     cout << endl;
    // }

    /*problem*/
    //               *
    //             * * *
    //           * * * * *
    //         * * * * * * *
    //       * * * * * * * * *
    //     * * * * * * * * * * *
    //   * * * * * * * * * * * * *
    // * * * * * * * * * * * * * * *

    //row + row+1
    // loop             // 0+1  1+2  2+3  3+4  4+5  5+6   6+7   7+8
    //number of stars   // 1 => 3 => 5 => 7 => 9 => 11 => 13 => 14

    // int rows = 5;
    // int spaces = (rows * 2) - 2;

    // rows => spaces
    // 1 => 0
    // 2 => 2
    // 3 => 4
    // 4 => 6
    // 5 => 8
    // 6 => 10
    // 7 => 12
    // 8 => 14

    // for (int y = 0; y < rows; y++)
    // {
    //     // print spaces
    //     for (int s = 0; s < spaces; s++)
    //     {
    //         cout << " ";
    //     }

    //     spaces -= 2;

    //     //printing stars
    //     for (int star = 0; star < (y + (y + 1)); star++)
    //     {
    //         cout << "* ";
    //     }

    //     cout << endl;
    // }

    /*problem*/
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10

    int rows = 5, counter = 1;
    for (int y = 1; y <= rows; y++)
    {
        for (int x = 1; x <= y; x++)
        {
            cout << counter << " ";
            counter++;
        }

        cout << endl;
    }

    return 0;
}