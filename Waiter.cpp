#include "Waiter.h"

int Waiter::getFloorNumber() const {
    return floorNumber;
}

Order Waiter::getOrder() const {
    return order;
}

void Waiter::setFloorNumber(int floorNumber) {
    Waiter::floorNumber = floorNumber;
}

Waiter &Waiter::operator=(const Waiter &rhs) {
    if(this != &rhs){
        Employee::operator=(rhs);
        floorNumber = rhs.floorNumber;
    }
    return *this;
}

ostream &operator<<(ostream &os, Waiter &waiter)  {
    os <<"Name: "<<waiter.name<<endl<<
       "Age: "<<waiter.age<<endl<<
       "Position: "<<waiter.position<<endl<<
       "Salary: "<<waiter.salary<<endl<<
       "Floor number: " << waiter.floorNumber << endl<<
       "Order: " << waiter.order<<endl;
    cout<<"-------------------------------------"<<endl;
    return os;
}

void Waiter::output(ostream &os) const {
    Employee::output(os);
    cout<<"Floor number: "<<floorNumber<<endl <<
        "Order: " << order <<endl;
}


Waiter::Waiter() {amountOfWaiters++;}

Waiter::Waiter(string name, int age)
        : Employee(name, age) {cout<<"Derived constructor"<<endl;amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary)
        : Employee(name, age, position, salary) {cout<<"Derived constructor"<<endl;amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary, int floorNumber)
        : Employee(name, age, position, salary), floorNumber{0} {cout<<"Derived constructor"<<endl;amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary, int floorNumber, Order order)
        : Employee(name, age, position, salary), floorNumber{floorNumber}, order{order} {cout<<"Derived constructor"<<endl;amountOfWaiters++;}

Waiter::~Waiter() {cout << "Derived destructor" << endl;}

Waiter::Waiter(const Waiter &other)
        : Employee(other), floorNumber{other.floorNumber} {cout << "Derived copy constructor" << endl;}

Waiter::Waiter(Waiter &&other) noexcept
        : Employee(other), floorNumber{other.floorNumber} {cout << "Derived move constructor" << endl;}



int Waiter::amountOfWaiters = 0;

int Waiter::getAmountOfWaiters() {
    return amountOfWaiters;
}

void Waiter::outputAmountOfEmployees() const {
    cout<<"Amount of waiters: "<<Waiter::getAmountOfWaiters()<<endl;
}







