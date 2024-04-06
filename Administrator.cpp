#include "Administrator.h"

int Administrator::getEntranceNumber() const {
    return entranceNumber;
}

Administrator &Administrator::operator=(const Administrator &rhs) {
    if(this != &rhs){
        Employee::operator=(rhs);
        entranceNumber = rhs.entranceNumber;
    }
    return *this;
}

ostream &operator<<(ostream &os, Administrator& administrator) {
    os <<"Name: "<<administrator.name<<endl<<
       "Age: "<<administrator.age<<endl<<
       "Position: "<<administrator.position<<endl<<
       "Salary: "<<administrator.salary<<endl<<
       "Entrance number: " << administrator.entranceNumber << endl;
    cout<<"-------------------------------------"<<endl;
    return os;
}

Administrator::Administrator() {amountOfAdministrators++;}

Administrator::Administrator(string name, int age)
        : Employee(name, age) {amountOfAdministrators++;}

Administrator::Administrator(string name, int age, string position, int salary)
        : Employee(name, age, position, salary) {amountOfAdministrators++;}

Administrator::Administrator(string name, int age, string position, int salary, int entranceNumber)
        : Employee(name, age, position, salary), entranceNumber{entranceNumber} {amountOfAdministrators++;}

Administrator::~Administrator() {}

Administrator::Administrator(const Administrator &other)
        : Employee(other), entranceNumber{other.entranceNumber} {}

Administrator::Administrator(Administrator &&other) noexcept
        : Employee(other), entranceNumber{other.entranceNumber} {}

void Administrator::output(ostream &os) const {
    Employee::output(os);
    cout<<"Entrance number: "<<entranceNumber<<endl;
}

int Administrator:: amountOfAdministrators = 0;

int Administrator::getAmountOfAdministrators() {
    return amountOfAdministrators;
}

void Administrator::outputAmountOfEmployees() const {
    cout<<"Amount of administrators: "<<Administrator::getAmountOfAdministrators()<<endl;
}

