#include <iostream>

using namespace std;

class Employee
{
    private:
        int salary;
    public:
        Employee()
        {
            setsalary(100);
        }
        void setsalary(int n)
        {
            this->salary = n;
        }
        void addsalary(int n)
        {
            this->salary += n;
        }
        int getsalary()
        {
           return this->salary;
        }
};

class Programmer: public Employee
{
    public:
        Programmer()
        {
            setsalary(500);
        }
};

class Manager: public Employee
{
    public:
        Manager()
        {
            setsalary(1000);
        }
        void bonussalary(int n)
        {
            setsalary(getsalary()*n);
        }
};
int main()
{
    Employee e;
    Programmer p;
    Manager m;
    p.addsalary(500);
    m.bonussalary(2);
    cout << e.getsalary() << endl;
    cout << p.getsalary() << endl;
    cout << m.getsalary() << endl;
}
