#include "Restaurant.h"
using namespace std;

string &Restaurant::getStatus() {
    return status;
}

string &Restaurant::getTitle() {
    return title;
}

string &Restaurant::getLocation() {
    return location;
}

Restaurant::Restaurant(string title, string location, string status)
        : title{title}, location{location}, status{status} {}

Restaurant::~Restaurant() {

}

void Restaurant::outputRestaurantInfo() {
    cout<<"Title: "<<title<<endl<<
        "Location: "<<location<<endl<<
        "Status: "<<status<<endl;
    cout<<"-------------------------------------"<<endl;
}








