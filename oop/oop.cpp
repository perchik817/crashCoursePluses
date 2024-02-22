#include <iostream>
#include <math.h>

using namespace std;
//классы от структур ничем не отличаются, кроме модификаторов доступа у классов
//модификаторы доступа работают только при компиляции

//struct Employee
//{
//    string name;
//    string lastName;
//    int number;
//    double grade;
//    char department;
//};

void printAllEmployees();
class Employee
{
private:
protected:
public:
    string name;
    string lastName;
    int number;
    double grade;
    char department;

    void setMaxGrade() {
        //this - указатель  (*this)->grade = 100;
        this->grade = 100;
        printAllEmployees();
    }
};
Employee departments[10];
void printAllEmployees() {
    //code
}

int main()
{
    Employee saya;
    saya.name = "Kyz Saikal";
    saya.lastName = "Tahirova";
    saya.department = 'c';
    saya.grade = 100;
    saya.number = 8888;
    cout << &saya << endl;
}
