#include <iostream>
using namespace std;

int moneyInterest(int money, float factor = 1.04)
{
    return money * factor;
}

//NOt work
// int moneyInterestRP(float factor = 1.04, int money)
// {
//     return money * factor;
// }

int main()
{
    int bankBalance = 1000000;
    cout << "Your Bank Balance: " << bankBalance << " you will recieve money after one year: " << moneyInterest(bankBalance) << endl;

    cout << "FOR VIP: Your Bank Balance: " << bankBalance << " you will recieve money after one year: " << moneyInterest(bankBalance, 1.5) << endl;

    //NOT WORK
    // cout << "Your Bank Balance: " << bankBalance << " you will recieve money after one year: " << moneyInterestRP(, bankBalance) << endl;
    return 0;
}