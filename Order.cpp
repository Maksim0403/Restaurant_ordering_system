#include "Order.h"

using namespace std;


string &Order::newItem() {
    return items;
}

int &Order::priceOfItem() {
    return price;
}
//const
void Order::setItems(const string &items) {
    this->items = items;
}

void Order::setPrice(int price) {
    this->price = price;
}
//overloading binary operator
Order Order::operator+(Order order2) {
    Order order;
    order.price = price + order2.price;
    order.items = items + order2.items;
    return order;
}

int Order::discount(int newPrice) {
    if(price >= 300){
        price -= newPrice;
    }
    return price;
}

std::istream &operator>>(istream &is, Order &order) {
    cout<<"Enter item: "<<endl;
    is>>order.items;
    cout<<"Enter price: "<<endl;
    is>>order.price;
    return is;
}

std::ostream &operator<<(ostream &os, Order &order) {
    os << "Item: "<< order.items <<endl<<
       "Price: "<< order.price <<endl<<
       "-------------------------------------"<<endl;
    return os;
}

Order::Order() {
    items = "";
    price = 0;
    cout<<"Constructor with no args was called"<<endl;
}

Order::Order(string items, int price)
        : items(items), price(price) {cout<<"Constructor was called"<<endl;}


Order::Order(const Order &other)
        :items(other.items), price(other.price) {cout<<"Copy constructor was called"<<endl;}


Order::~Order() {}


void Order::outputOrderInfo() {
    Order::discount(50);
    cout<<"Item: "<< items <<endl<<
        "Price: "<<price<<endl;
        cout<<"-------------------------------------"<<endl;
}



