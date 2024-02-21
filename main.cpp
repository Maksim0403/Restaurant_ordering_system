#include <iostream>
#include <cstring>
#include "Restaurant.cpp"
#include "Employee.cpp"
#include "Order.cpp"

using namespace std;

/*
plan:
 theme: restaurant ordering system
 1. class restaurant (title, location, status)
 2. class employee (name, age, position, salary)
 3. class order (items, price)
*/

int main() {
    Restaurant rest1("Aristocrat", "Holovna", "Opened");
    Restaurant rest2;

    rest1.outputRestaurantInfo();
    rest2.outputRestaurantInfo();

    Employee employee1("Fred", 21, "Waiter", 2000);
    Employee employee2("John", 24, "Admin");
    Employee employee3("Alex", 22);
    Employee employee4("Kevin");

    employee1.outputEmployeeInfo();

    employee1.setSalary(1000);
    cout<<"New salary: "<<employee1.getSalary()<<endl;
    cout<<"-------------------------------------"<<endl;

    employee2.outputEmployeeInfo();
    employee3.outputEmployeeInfo();
    employee4.outputEmployeeInfo();

    Order menu("Salad", 220);
    Order menu1("Fries", 120);
    Order *lastMenu = new Order("Steak", 200);

    menu.outputOrderInfo();
    menu1.outputOrderInfo();
    lastMenu->outputOrderInfo();

    delete lastMenu;
    return 0;
}
