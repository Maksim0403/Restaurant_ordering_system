#include <iostream>
#include <cstring>
#include "Employee.h"
using namespace std;

#ifndef LAB2_CLASS_OBJECTS_ADMINISTRATOR_H
#define LAB2_CLASS_OBJECTS_ADMINISTRATOR_H


class Administrator : public Employee {
protected:
    int entranceNumber;
    static int amountOfAdministrators;
public:
    friend ostream &operator<<(ostream &os, Administrator& administrator);

    Administrator();
    Administrator(string name, int age);
    Administrator(string name, int age, string position, int salary);
    Administrator(string name, int age, string position, int salary, int entranceNumber);
    virtual ~Administrator();
    Administrator(const Administrator &other);
    Administrator(Administrator &&other) noexcept;
    Administrator& operator=(const Administrator &rhs);

    static int getAmountOfAdministrators();
    int getEntranceNumber() const;

    void output(ostream &os) const override final;
    void outputAmountOfEmployees() const override;
};


#endif //LAB2_CLASS_OBJECTS_ADMINISTRATOR_H
