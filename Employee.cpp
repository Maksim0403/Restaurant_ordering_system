#include "Employee.h"
#include "Waiter.h"

using namespace std;

//const
string Employee::getName() const {
    return name;
}

int &Employee::getAge() {
    return age;
}

string Employee::getPosition() const {
    return position;
}

int &Employee::getSalary() {
    return salary;
}

//using this
void Employee::setSalary(int money) {
    this->salary = money;
}

void Employee::setName(string name) {
    this->name = name;
}

void Employee::setAge(int age) {
    this->age = age;
}

void Employee::setPosition(string &position) {
    this->position = position;
}

int Employee::amountOfEmployees = 0;

int Employee::getAmountOfEmployees() {
    return amountOfEmployees;
}

void Employee::outputAmountOfEmployees() const {
    cout << "Amount of employees: " << Employee::getAmountOfEmployees() << endl;
}


Employee &Employee::operator=(const Employee &rhs) {
    if (this != &rhs) {
        salary = rhs.salary;
    }
    return *this;
}

ostream &operator<<(ostream &os,const  Employee &employee) {
    os << "Employee (Name: " << employee.name <<
       ", Age: " << employee.age <<
       ", Position: " << employee.position <<
       ", Salary: " << employee.salary << ")"<< endl;
    return os;
}

void Employee::output(ostream &os) const {
    cout << "Name: " << name << endl <<
         "Age: " << age << endl <<
         "Position: " << position << endl <<
         "Salary: " << salary << endl;
}

Employee::Employee()
        : Employee{"None", 0, "Undefined", 0} {
    //cout << "Constructor with no args was called" << endl;
    amountOfEmployees++;
}

Employee::Employee(string name)
        : Employee{name, 0, "Undefined", 0} {
    //cout << "Constructor was called" << endl;
    amountOfEmployees++;
}

Employee::Employee(string name, int age)
        : Employee{name, age, "Undefined", 0} {
    //cout << "Constructor was called" << endl;
    amountOfEmployees++;
}

Employee::Employee(string name, int age, string position)
        : Employee{name, age, position, 0} {
    //cout << "Constructor was called" << endl;
    amountOfEmployees++;
}

Employee::Employee(string name, int age, string position, int salary)
        : name(name), age(age), position(position), salary(salary) {
    //cout << "Constructor was called" << endl;
    amountOfEmployees++;
}

//Copy constructor
Employee::Employee(const Employee &other)
        : name(other.name), age(other.age), position(other.position), salary(other.salary) {
    //cout << "Copy constructor was called" << endl;
}

//Move constructor
Employee::Employee(Employee &&other) noexcept
        : name(other.name), age(other.age), position(other.position), salary(other.salary) {
    //cout << "Move constructor was called" << endl;
}

Employee::~Employee() {
    //cout << "Destructor was called" << endl;
    amountOfEmployees--;
}

