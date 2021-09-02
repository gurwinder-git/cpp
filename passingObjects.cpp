#include <iostream>
using namespace std;

class Number
{
public:
    int a, b;

public:
    void setNumbers(int x, int y)
    {
        a = x;
        b = y;
    }
};

class ProccessObject
{
public:
    //with pointers
    int proccessObjectMethodP(Number *obj)
    {
        cout << "address obj: " << (obj) << endl;
        // cout << "address obj.a: " << obj.a << endl;
        // cout << "address obj.b: " << obj.b << endl;

        (*obj).a = 12;
        (*obj).b = 12;
        return ((*obj).a + (*obj).b);
    }

    //with refrence
    int proccessObjectMethodR(Number &obj)
    {
        obj.a = 12;
        obj.b = 12;
        return (obj.a + obj.b);
    }
};

int main()
{
    Number n1Obj;
    n1Obj.setNumbers(2, 4);

    ProccessObject tObj;

    cout << "Changing and returning: " << tObj.proccessObjectMethodP(&n1Obj) << endl;

    cout << "a: " << n1Obj.a << endl;
    cout << "b: " << n1Obj.b << endl;

    return 0;
}