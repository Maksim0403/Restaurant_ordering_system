#include <iostream>
#include <cstring>
#include "Printable.h"

using namespace std;
#ifndef LAB2_CLASS_OBJECTS_RESTAURANT_H
#define LAB2_CLASS_OBJECTS_RESTAURANT_H

class Restaurant : public Printable {
private:
    string title;
    string location;
    string status;
public:
    //overloading friend operators
    friend std::ostream& operator<< (std::ostream &os, const Restaurant &restaurant);

    Restaurant();
    Restaurant(string newTitle = "None", string newLocation = "None", string status = "Undefined");
    Restaurant(const Restaurant &other);
    virtual ~Restaurant();

    string getTitle() const;
    string getLocation() const;
    string &getStatus();

    void setTitle(const string &title);
    void setLocation(const string &location);
    void setStatus(string &status);

    void output(ostream &os) const override;
};


#endif //LAB2_CLASS_OBJECTS_RESTAURANT_H
