#include <iostream>
using namespace std;

class Student
{
private:
    double mobileNumber;

public:
    int id, age;

public:
    int setStudent(int id1, int age1, double mobile)
    {
        id = id1;
        age = age1;
        mobileNumber = mobile;
        return 0;
    }
    int getMobile()
    {
        return mobileNumber;
    }
    int getStudent()
    {
        cout << "student id: " << id << endl;
        cout << "student age: " << age << endl;
        cout << "student mobile: " << mobileNumber << endl;
        return 0;
    }
};

int main()
{
    Student std1;
    std1.setStudent(1905420, 23, 7009380803);
    cout << std1.getMobile() << endl;
    std1.getStudent();

    return 0;
}
