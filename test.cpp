#include <iostream>

using namespace std;

class basic
{
private:
public:
    int data;
    pair<int, int> p;
    basic(int a, int p1, int p2)
    {
        data = a;
        p.first = p1;
        p.second = p2;
    }

    int &getData()
    {
        return data;
    }

    pair<int, int> &getPair()
    {
        return p;
    }
};

int &test(int &a)
{
    a = 1000;
    return a;
}

int main()
{

    int a = 6;
    int &d = test(a); // bad practice
    d = 0;
    cout << a << endl;
    cout << d << endl;
    basic b(2, 12, 13);
    // int &getData = b.getData();

    // getData = 100;
    // cout << b.data << endl;
    // cout << b.getData();

    // pair<int, int> &res = b.getPair();
    // res.first = 99949;
    // res.second = 11111;
    // cout << b.p.first << endl;
    // cout << b.p.second << endl;
    // cout << res.first << endl;
    // cout << res.second;

    return 0;
}