#include <iostream>
#include <cstring>

using namespace std;
#ifndef LAB2_CLASS_OBJECTS_PRINTABLE_H
#define LAB2_CLASS_OBJECTS_PRINTABLE_H

/*1. Static Binding example
 *  friend ostream &operator<<(ostream &os, const Order &obj);
    friend ostream &operator<<(ostream &os, const Waiter &obj);
    friend ostream &operator<<(ostream &os, const Administrator  &obj);
 * */

class Printable {
    friend ostream &operator<<(ostream &os, const Printable &obj);
public:
    virtual void output(ostream &os) const = 0;

    virtual ~Printable();


};


#endif //LAB2_CLASS_OBJECTS_PRINTABLE_H
