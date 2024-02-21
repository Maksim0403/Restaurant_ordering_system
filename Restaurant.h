#include <iostream>
#include <cstring>
using namespace std;
#ifndef LAB2_CLASS_OBJECTS_RESTAURANT_H
#define LAB2_CLASS_OBJECTS_RESTAURANT_H

class Restaurant {
private:
    string title;
    string location;
    string status;
public:
    Restaurant(string newTitle = "None", string newLocation = "None", string status = "Undefined");
    virtual ~Restaurant();

    string &getTitle();
    string &getLocation();
    string &getStatus();
    void outputRestaurantInfo();
};


#endif //LAB2_CLASS_OBJECTS_RESTAURANT_H
