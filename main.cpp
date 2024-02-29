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
    Restaurant rest1{"Aristocrat", "Holovna", "Opened"};
    Restaurant rest2{"Lavanda"};
    Restaurant rest3(rest1);

    cout<<rest1<<rest2<<rest3;
    //rest1.outputRestaurantInfo();
    //rest2.outputRestaurantInfo();
    //rest3.outputRestaurantInfo();

    Employee employee1{"Fred", 21, "Waiter", 2000};
    Employee employee2{"John", 24, "Admin"};
    Employee employee3{"Alex", 22};
    Employee employee4{};
    Employee salaryPlus = + employee2;

    employee1.outputEmployeeInfo();
    employee1.setSalary(1000);
    employee1.outputEmployeeInfo();
    salaryPlus.outputEmployeeInfo();
    employee3.outputEmployeeInfo();
    employee4.outputEmployeeInfo();
    Employee::outputAmountOfEmployees();


    Order menu("Salad ", 220);
    Order menu1("Fries ", 320);
    Order *lastMenu = new Order("Steak ", 280);
    Order otherMenu(menu);
    Order orderMinus = menu1 + menu;
    Order menu2;

    orderMinus.outputOrderInfo();
    menu.outputOrderInfo();
    menu1.outputOrderInfo();
    otherMenu.outputOrderInfo();
    lastMenu->outputOrderInfo();

    cin>>menu2;
    cout<<menu2;

    delete lastMenu;
    return 0;
}
