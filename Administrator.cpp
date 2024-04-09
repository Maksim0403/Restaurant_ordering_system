#include "Administrator.h"

int Administrator::getEntranceNumber() const {
    return entranceNumber;
}

Administrator &Administrator::operator=(const Administrator &rhs) {
    if (this != &rhs) {
        Employee::operator=(rhs);
        entranceNumber = rhs.entranceNumber;
    }
    return *this;
}

//Administrator (Name: Ivan, Age: 34, Position: Administrator, Salary: 3000, Entrance number: 2)
ostream &operator<<(ostream &os,const  Administrator &administrator) {
    os << "Administrator (Name: " << administrator.name << ", Age: " << administrator.age << ", Position: "
       << administrator.position << ", Salary: " << administrator.salary << ", Entrance number: "
       << administrator.entranceNumber << ")" << endl;
    return os;
}

Administrator::Administrator() { amountOfAdministrators++; }

Administrator::Administrator(string name, int age)
        : Employee(name, age) { amountOfAdministrators++; }

Administrator::Administrator(string name, int age, string position, int salary)
        : Employee(name, age, position, salary) { amountOfAdministrators++; }

Administrator::Administrator(string name, int age, string position, int salary, int entranceNumber)
        : Employee(name, age, position, salary), entranceNumber{entranceNumber} { amountOfAdministrators++; }

Administrator::~Administrator() {}

Administrator::Administrator(const Administrator &other)
        : Employee(other), entranceNumber{other.entranceNumber} {}

Administrator::Administrator(Administrator &&other) noexcept
        : Employee(other), entranceNumber{other.entranceNumber} {}

void Administrator::output(ostream &os) const {
    Employee::output(os);
    cout << "Entrance number: " << entranceNumber << endl;
}

int Administrator::amountOfAdministrators = 0;

int Administrator::getAmountOfAdministrators() {
    return amountOfAdministrators;
}

void Administrator::outputAmountOfEmployees() const {
    cout << "Amount of administrators: " << Administrator::getAmountOfAdministrators() << endl;
}

