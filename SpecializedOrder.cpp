#include "SpecializedOrder.h"


int SpecializedOrder::getAmountOfPlaces() {
    return amountOfPlaces;
}

SpecializedOrder::SpecializedOrder() {}

SpecializedOrder::SpecializedOrder(string items, int price)
        : Order(items, price) {}

SpecializedOrder::SpecializedOrder(string items, int price, int amountOfPlaces)
        : Order(items, price) {}

SpecializedOrder::~SpecializedOrder() {}

