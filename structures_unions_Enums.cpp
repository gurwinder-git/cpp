#include <iostream>
using namespace std;

struct nested
{
    int data;
};

struct student
{
    char name;           //1
    unsigned int rollno; //4
    int marks;           //4
    struct nested n1;    //4
    int double_marks()   //4
    {
        return marks * 2;
    }

    //total 17 bytes
};

typedef student sd;
typedef int myint;

// In union we can use only one data feild
union money
{
    int Indian; //4
    int USD;    //4
    int CAD;    //4
    // total 4 bytes
    //maximum size will be assigned
};

int main()
{

    // myint a = 10;
    // cout << a << endl;

    // struct student std1;
    cout << "---------Student 1--------" << endl;
    sd std1;
    std1.name = 'G';
    std1.rollno = 1905420;
    std1.marks = 100;
    std1.n1.data = 123;

    cout << "value of std1 " << std1.name << endl;
    cout << "value of std1 " << std1.rollno << endl;
    cout << "value of std1 " << std1.marks << endl;
    cout << "function " << std1.double_marks() << endl;
    cout << "nested data " << std1.n1.data << endl;

    cout << "---------Student 2--------" << endl;

    sd std2;
    std2.name = 'L';
    std2.rollno = 207823;
    std2.marks = 50;

    cout << "value of std1 " << std2.name << endl;
    cout << "value of std1 " << std2.rollno << endl;
    cout << "value of std1 " << std2.marks << endl;
    cout << "function " << std2.double_marks() << endl;

    cout << "-----------Union--------- " << endl;

    union money M1;

    M1.Indian = 5000;
    cout << M1.Indian << endl;
    M1.CAD = 100;
    cout << M1.Indian << endl;
    cout << M1.CAD << endl;

    cout << "-----------enum--------- " << endl;

    enum Meal
    {
        rice,
        lunch,
        roti
    };

    cout << rice << endl;
    cout << lunch << endl;
    cout << roti << endl;

    return 0;
}
