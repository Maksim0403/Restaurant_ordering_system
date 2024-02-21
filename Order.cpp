#include "Order.h"

using namespace std;

string &Order::newItem() {
    return items;
}

int &Order::priceOfItem() {
    return price;
}

Order::Order(string items, int price)
        : items(items), price(price) {}

Order::~Order() {}

void Order::outputOrderInfo() {
    cout<<"Item: "<< items <<endl<<
        "Price: "<<price<<endl;
        cout<<"-------------------------------------"<<endl;
}



