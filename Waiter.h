#include <iostream>
#include <cstring>
#include "Employee.h"
#include "Order.h"

using namespace std;
#ifndef LAB2_CLASS_OBJECTS_WAITER_H
#define LAB2_CLASS_OBJECTS_WAITER_H


class Waiter : public Employee{
private:
    int floorNumber;
    Order order;
public:

    friend ostream &operator<<(ostream &os, Waiter &waiter);

    Waiter();
    Waiter(string name, int age);
    Waiter(string name, int age, string position, int salary);
    Waiter(string name, int age, string position, int salary, int floorNumber, Order order);
    virtual ~Waiter();
    Waiter(const Waiter &other);
    Waiter(Waiter &&other) noexcept;
    Waiter& operator=(const Waiter &rhs);

    int getFloorNumber() const;


};

#endif //LAB2_CLASS_OBJECTS_WAITER_H
