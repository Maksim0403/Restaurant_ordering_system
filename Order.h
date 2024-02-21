#include <iostream>
#include <cstring>
using namespace std;

#ifndef LAB2_CLASS_OBJECTS_FOOD_H
#define LAB2_CLASS_OBJECTS_FOOD_H

class Order {
private:
    string items;
    int price;
public:
    Order(string items, int price);
    ~Order();

    string &newItem();
    int &priceOfItem();
    void outputOrderInfo();
};



#endif //LAB2_CLASS_OBJECTS_FOOD_H
