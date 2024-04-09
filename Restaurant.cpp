#include "Restaurant.h"
using namespace std;

string &Restaurant::getStatus() {
    return status;
}

string Restaurant::getTitle() const {
    return title;
}

string Restaurant::getLocation() const {
    return location;
}

void Restaurant::setTitle(const string &title) {
    this->title = title;
}

void Restaurant::setLocation(const string &location) {
    this->location = location;
}

void Restaurant::setStatus(string &status) {
    Restaurant::status = status;
}

ostream &operator<<(ostream &os, const Restaurant &restaurant) {
    os << "Restaurant (Title: " << restaurant.title <<
        ", Location: " << restaurant.location <<
        ", Status: " << restaurant.status << ")" << endl;
    return os;
}

Restaurant::Restaurant() {

}

Restaurant::Restaurant(string title, string location, string status)
        : title{title}, location{location}, status{status} {}

Restaurant::Restaurant(const Restaurant &other)
        :title(other.title), location(other.location), status(other.status) {}

Restaurant::~Restaurant() {
}

void Restaurant::output(ostream &os) const {
    cout<<"Title: "<<title<<endl<<
        "Location: "<<location<<endl<<
        "Status: "<<status<<endl;
}













