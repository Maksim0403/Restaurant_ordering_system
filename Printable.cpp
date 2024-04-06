#include "Printable.h"

ostream &operator<<(ostream &os, const Printable &obj) {
    obj.output(os);
    return os;
}

Printable::~Printable() {

}

istream &operator>>(istream &is, const Printable &obj) {
    return is;
}
