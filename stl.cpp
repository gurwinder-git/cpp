#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// using std::vector;
using namespace std;

template <class type>
class myArray
{
private:
    type *a;

public:
    myArray(type a[])
    {
        this->a = a;
    }

    type operator[](int i)
    {
        return a[i];
    }
};

int main()
{
    int a[] = {1, 2, 3};
    myArray<int> ptrToObj = a;

    cout << ptrToObj[1];

    return 0;
}