#include <iostream>
#include <cstring>
#include "Printable.h"

using namespace std;

#ifndef LAB2_CLASS_OBJECTS_FOOD_H
#define LAB2_CLASS_OBJECTS_FOOD_H

class Order : public Printable {
protected:
    string items;
    int price;
public:
    friend std::istream& operator>> (std::istream &is, Order& order);
    friend std::ostream& operator<< (std::ostream &os, const Order& order);

    Order();
    Order(const Order &other);
    Order(string items, int price);
    //Order operator+(Order order2);
    ~Order();

    int discount(int newPrice);
    void setItems(const string &items);
    void setPrice(int price);
    string &newItem();
    int &priceOfItem();

    void output(ostream &os) const final;

    static int order;
};



#endif //LAB2_CLASS_OBJECTS_FOOD_H
