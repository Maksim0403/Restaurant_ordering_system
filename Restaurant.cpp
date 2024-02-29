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
    os << "Title: "<<restaurant.title<<endl<<
        "Location: "<<restaurant.location<<endl<<
        "Status: "<<restaurant.status<<endl<<
        "-------------------------------------"<<endl;
    return os;
}

Restaurant::Restaurant() {
        cout<<"Constructor with no args was called"<<endl;
}

Restaurant::Restaurant(string title, string location, string status)
        : title{title}, location{location}, status{status} {cout<<"Constructor was called"<<endl;}

Restaurant::Restaurant(const Restaurant &other)
        :title(other.title), location(other.location), status(other.status) {cout<<"Copy constructor was called"<<endl;}

Restaurant::~Restaurant() {
    cout<<"Destructor was called"<<endl;
}


void Restaurant::outputRestaurantInfo() {
    cout<<"Title: "<<title<<endl<<
        "Location: "<<location<<endl<<
        "Status: "<<status<<endl;
    cout<<"-------------------------------------"<<endl;
}











