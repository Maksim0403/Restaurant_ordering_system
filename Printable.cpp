#include "Printable.h"

ostream &operator<<(ostream &os, const Printable &obj) {
    obj.output(os);
    return os;
}

Printable::~Printable() {

}
