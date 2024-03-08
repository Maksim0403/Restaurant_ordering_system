#include "Waiter.h"

int Waiter::getFloorNumber() const {
    return floorNumber;
}

Waiter::Waiter() {}

Waiter::Waiter(string name, int age)
        : Employee(name, age) {cout<<"Derived constructor"<<endl;}

Waiter::Waiter(string name, int age, string position, int salary)
        : Employee(name, age, position, salary) {cout<<"Derived constructor"<<endl;}

Waiter::Waiter(string name, int age, string position, int salary, int floorNumber, Order order)
        : Employee(name, age, position, salary), floorNumber{floorNumber}, order{order} {cout<<"Derived constructor"<<endl;}

Waiter::~Waiter() {cout << "Derived destructor" << endl;}

Waiter::Waiter(const Waiter &other)
        : Employee(other), floorNumber{other.floorNumber} {cout << "Derived copy constructor" << endl;}

Waiter::Waiter(Waiter &&other) noexcept
        : Employee(other), floorNumber{other.floorNumber} {cout << "Derived move constructor" << endl;}

Waiter &Waiter::operator=(const Waiter &rhs) {
    if(this != &rhs){
        Employee::operator=(rhs);
        floorNumber = rhs.floorNumber;
    }
    return *this;
}

ostream &operator<<(ostream &os, Waiter &waiter) {
    os <<"Name: "<<waiter.name<<endl<<
           "Age: "<<waiter.age<<endl<<
           "Position: "<<waiter.position<<endl<<
           "Salary: "<<waiter.salary<<endl<<
           "Floor number: " << waiter.floorNumber << endl<<
           "Order: " << waiter.order<<endl;
    cout<<"-------------------------------------"<<endl;
    return os;
}

