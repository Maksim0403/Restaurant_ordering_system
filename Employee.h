#include <iostream>
#include <cstring>
#include "Printable.h"

using namespace std;
#ifndef LAB2_CLASS_OBJECTS_WORKERS_H
#define LAB2_CLASS_OBJECTS_WORKERS_H

class Employee : public Printable{
protected:
    string name;
    int age;
    string position;
    int salary;
    static int amountOfEmployees;
public:
    friend ostream &operator<<(ostream &os, Employee &employee);

    Employee();
    Employee(string name);
    Employee(string name, int age);
    Employee(string name, int age, string position);
    Employee(string name, int age, string position, int salary);
    Employee(const Employee &other);
    Employee(Employee &&other) noexcept;
    Employee& operator=(const Employee &rhs);
    virtual ~Employee();

    static int getAmountOfEmployees();

    string getName() const;
    int &getAge();
    string getPosition() const;
    int &getSalary();

    void setSalary(int money);
    void setName(string name);
    void setAge(int age);
    void setPosition(string &position);

    void output(ostream &os) const override;
    virtual void outputAmountOfEmployees() const;
};


#endif //LAB2_CLASS_OBJECTS_WORKERS_H
