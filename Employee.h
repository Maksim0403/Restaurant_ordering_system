#include <iostream>
#include <cstring>
using namespace std;
#ifndef LAB2_CLASS_OBJECTS_WORKERS_H
#define LAB2_CLASS_OBJECTS_WORKERS_H

class Employee {
private:
    string name;
    int age;
    string position;
    int salary;
public:
    Employee();
    Employee(string name);
    Employee(string name, int age);
    Employee(string name, int age, string position);
    Employee(string name, int age, string position, int salary);
    virtual ~Employee();


    string &getName();
    int &getAge();
    string &getPosition();
    void setSalary(int money);
    int &getSalary();
    void outputEmployeeInfo();
};



#endif //LAB2_CLASS_OBJECTS_WORKERS_H
