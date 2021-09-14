#include <iostream>
#include <iterator>
#include <list>

using namespace std;

//////////////////////////////////////////////
// class test
// {
// public:
//     int var1;

//     test(int a)
//     {
//         var1 = a;
//     }

//     void operator+(test &t1)
//     {
//         cout << t1.var1 + var1 << endl;
//     }
// };

// void operator+(test &t1, int a)
// {
//     cout << t1.var1 + a << endl;
// }

// int main()
// {
//     int a = 10;
//     int b = 5;

//     test t1(100);
//     test t2(10);
//     // cout.operator<<(a);
//     //  operator+(t1, t2);
//     t1 + t2;
//     t1 + 2;

//     return 0;
// }
////////////////////////////////////////

class youtube
{
public:
    string name;
    int totalsubscriber;

    youtube(string n, int ts)
    {
        name = n;
        totalsubscriber = ts;
    }
};

class myCollection
{
public:
    list<youtube> collect;

    void operator+=(youtube &obj)
    {
        collect.push_back(obj);
    }
};

ostream &operator<<(ostream &coutObj, youtube &ytObj)
{
    coutObj << ytObj.name << endl;
    return coutObj;
}

int main()
{
    // youtube yt1 = youtube("GUrwinder", 100088);
    youtube yt1("GUrwinder", 100088);
    youtube yt2("inder", 88);
    cout << yt1 << yt2;
    operator<<(cout, yt1) << (cout, yt2);
    myCollection coll1;
    coll1 += yt1;

    return 0;
}