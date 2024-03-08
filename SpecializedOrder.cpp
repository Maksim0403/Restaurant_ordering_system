#include "SpecializedOrder.h"


int SpecializedOrder::getAmountOfPlaces() {
    return amountOfPlaces;
}

SpecializedOrder::SpecializedOrder() {cout<<"Derived constructor"<<endl;}

SpecializedOrder::SpecializedOrder(string items, int price)
        : Order(items, price) {cout<<"Derived constructor"<<endl;}

SpecializedOrder::SpecializedOrder(string items, int price, int amountOfPlaces)
        : Order(items, price) {cout<<"Derived constructor"<<endl;}

SpecializedOrder::~SpecializedOrder() {cout << "Derived destructor" << endl;}

