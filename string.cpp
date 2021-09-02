#include <iostream>
#include <string>
using namespace std;

int main()
{

    // char s[] = "Guru";
    char s1[] = {'G', 'u', 'r', 'i', '\n', 's', 'i', 'n', 'g', 'h'};
    // cout << s[0] << endl;
    // cout << s[1] << endl;
    // cout << s[2] << endl;
    // cout << s[3] << endl;
    // cout << s1[0] << endl;
    // cout << s1[1] << endl;
    // cout << s1[2] << endl;
    // cout << s1[3] << endl;

    char *str = s1;
    cout << *str;
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);
    cout << *(str += 1);

    cout << endl;

    string myString = {'G', 'u', 'r', 'u'};
    cout << myString;

        return 0;
}