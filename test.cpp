#include <iostream>
#include <vector>

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

vector<int> testObj()
{
    vector<int> res({2, 45, 6});
    cout << &res << endl;

    return res;
}
int main()
{

    vector<int> ans = testObj();

    // cout << &ans;

    int a = 6;
    int &d = test(a); // bad practice
    d = 0;
    // cout << a << endl;
    // cout << d << endl;
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

    vector<vector<int>> nums = {{1, 2, 3, 4, 5, 6, 7}, {8, 9, 10, 11, 12, 13, 14}};

    vector<int> temp = nums[0];
    nums[0] = nums[1];
    nums[1] = temp;

    cout << nums[0][0];

    return 0;
}