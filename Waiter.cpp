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

ostream &operator<<(ostream &os, const Waiter &waiter)  {
    os << "Waiter (Name: "<<waiter.name <<
       ", Age: "<<waiter.age <<
       ", Position: "<<waiter.position <<
       ", Salary: "<<waiter.salary <<
       ", Floor number: " << waiter.floorNumber <<
       ", Order: " << waiter.order << ")" << endl;
    return os;
}

void Waiter::output(ostream &os) const {
    Employee::output(os);
    cout<<"Floor number: "<<floorNumber<<endl <<
        "Order: " << order <<endl;
}


Waiter::Waiter() {amountOfWaiters++;}

Waiter::Waiter(string name, int age)
        : Employee(name, age) {amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary)
        : Employee(name, age, position, salary) {amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary, int floorNumber)
        : Employee(name, age, position, salary), floorNumber{0} {amountOfWaiters++;}

Waiter::Waiter(string name, int age, string position, int salary, int floorNumber, Order order)
        : Employee(name, age, position, salary), floorNumber{floorNumber}, order{order} {amountOfWaiters++;}

Waiter::~Waiter() {}

Waiter::Waiter(const Waiter &other)
        : Employee(other), floorNumber{other.floorNumber} {}

Waiter::Waiter(Waiter &&other) noexcept
        : Employee(other), floorNumber{other.floorNumber} {}



int Waiter::amountOfWaiters = 0;

int Waiter::getAmountOfWaiters() {
    return amountOfWaiters;
}

void Waiter::outputAmountOfEmployees() const {
    cout<<"Amount of waiters: "<<Waiter::getAmountOfWaiters()<<endl;
}







