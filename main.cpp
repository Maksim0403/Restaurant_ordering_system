#include <iostream>
#include <cstring>
#include "Restaurant.h"

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
    return 0;
}
