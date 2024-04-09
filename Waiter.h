#include <iostream>
#include <cstring>
#include "Employee.h"
#include "Order.h"

using namespace std;
#ifndef LAB2_CLASS_OBJECTS_WAITER_H
#define LAB2_CLASS_OBJECTS_WAITER_H


class Waiter : public Employee {
protected:

    int floorNumber;
    Order order;
    static int amountOfWaiters;
public:
    friend ostream &operator<<(ostream &os, const Waiter &waiter);

    Waiter();
    Waiter(string name, int age);
    Waiter(string name, int age, string position, int salary);
    Waiter(string name, int age, string position, int salary, int floorNumber);
    Waiter(string name, int age, string position, int salary, int floorNumber, Order order);
    virtual ~Waiter();
    Waiter(const Waiter &other);
    Waiter(Waiter &&other) noexcept;
    Waiter& operator=(const Waiter &rhs);

    void setFloorNumber(int floorNumber);

    int getFloorNumber() const;
    Order getOrder() const;

    static int getAmountOfWaiters();

    void output(ostream &os) const override final;
    void outputAmountOfEmployees() const override;
};

#endif //LAB2_CLASS_OBJECTS_WAITER_H
