#include <iostream>
#include <cstring>
#include "Order.h"
using namespace std;

#ifndef LAB2_CLASS_OBJECTS_SPECIALIZEDORDER_H
#define LAB2_CLASS_OBJECTS_SPECIALIZEDORDER_H


class SpecializedOrder : public Order {
private:
    int amountOfPlaces;
public:
    SpecializedOrder();
    SpecializedOrder(string items, int price);
    SpecializedOrder(string items, int price, int amountOfPlaces);
    ~SpecializedOrder();

    int getAmountOfPlaces();
};




#endif //LAB2_CLASS_OBJECTS_SPECIALIZEDORDER_H
