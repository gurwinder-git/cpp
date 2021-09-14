#include <iostream>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//        or class
template <typename type = int, class type2 = int>
class master
{
public:
    int size;
    type *arrPtr;

    master(int size)
    {
        this->size = size;
        arrPtr = new type[size];
    }

    type sum(master &obj)
    {
        type sum = 0;
        for (int i = 0; i < obj.size; i++)
        {
            sum += *((obj.arrPtr) + i);
        }
        return (sum);
    }

    void insertElements(int index, type element)
    {
        arrPtr[index] = element;
    }
};

int main()
{
    master<float> obj(5);
    obj.insertElements(0, 1.7);
    obj.insertElements(1, 2.8);
    obj.insertElements(2, 3.0);
    obj.insertElements(3, 4.5);
    obj.insertElements(4, 5.3);
    int s = obj.sum(obj);
    cout << s << endl;

    int *a = new int[10]{1, 3, 4, 6, 7, 8};
    cout << *(a + 0);
    cout << a[1];
    cout << a[2];
    cout << a[3];
    cout << a[4];

    return 0;
}
