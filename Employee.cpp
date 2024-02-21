#include "Employee.h"
using namespace std;

string &Employee::getName() {
    return name;
}

int &Employee::getAge() {
    return age;
}

string &Employee::getPosition() {
    return position;
}

void Employee::setSalary(int money) {
    salary = money;
}

int &Employee::getSalary() {
    return salary;
}

Employee::Employee()
        : Employee{"None", 0, "Undefined", 0}{}

Employee::Employee(string name)
        : Employee{name, 0, "Undefined", 0}{}

Employee::Employee(string name, int age)
        : Employee{name, age, "Undefined", 0}{}

Employee::Employee(string name, int age, string position)
        : Employee{name, age, position, 0} {}

Employee::Employee(string name, int age, string position, int salary)
        : name(name), age(age), position(position), salary(salary) {}

Employee::~Employee() {

}

void Employee::outputEmployeeInfo() {
    cout<<"Name: "<<name<<endl<<
        "Age: "<<age<<endl<<
        "Position: "<<position<<endl<<
        "Salary: "<<salary<<endl;
    cout<<"-------------------------------------"<<endl;
}










