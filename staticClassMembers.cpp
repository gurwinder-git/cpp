#include <iostream>
using namespace std;

class Employe
{
private:
    static long int id;
    string name;
    long int salary;

public:
    void setEmp(string name1, long int salary1)
    {
        cout << "your name has " << name1.length() << " characters" << endl;
        name = name1;
        salary = salary1;
        ++id;
    }

    int getTotalEmployes()
    {
        return (id - 1001);
    }

    static int getTotalEmployesStaticVersion()
    {
        return (id - 1001);
    }
};

long int Employe ::id = 1001;

int main()
{
    Employe e1, e2, e3;
    string s1 = "Gurwinder";
    e1.setEmp(s1, 32534534);
    e2.setEmp("Baljinder", 23492698);
    e3.setEmp("Anshu", 3432423);

    cout << e1.getTotalEmployes() << endl;
    cout << Employe::getTotalEmployesStaticVersion();

    return 0;
}