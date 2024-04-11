#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <stdexcept>
#include "Restaurant.cpp"
#include "Employee.cpp"
#include "Order.cpp"
#include "Waiter.h"
#include "SpecializedOrder.h"
#include "Administrator.h"

using namespace std;

/*
plan:
 theme: restaurant ordering system
 1. class restaurant (title, location, status)
 2. class employee (className, age, position, salary)
 3. class order (items, price)
*/

enum class User {
    user, admin, undefined
};

enum class Database {
    administators, employees, orders, restaurants, waiters, undefined
};

User login() {
    string username;
    User usertype = User::undefined;

    cout << "*-*-*-*-*-*-*-Login-*-*-*-*-*-*-*" << endl;
    cout << "Input username: " << endl;
    cin >> username;

    if (username == "admin") {
        string password;
        cout << "Input password: " << endl;
        cin >> password;

        if (password == "admin") {
            usertype = User::admin;
        } else {
            cout << "Incorrect credentials!" << endl;
        }
    } else {
        usertype = User::user;
    }

    cout << "Login successful!" << endl;
    return usertype;
}


void userActivity(string text){
    string fileName = "userActivity.txt";
    ofstream write;
    write.open(fileName, ios_base::app);
    if (!write.is_open()) {
        cerr << "File opening error!" << endl;
    } else {
        write << text << endl;
    }
    write.close();
}

Database selectDatabase() {
    int fileNumber;
    cin >> fileNumber;

    Database database;

    switch (fileNumber) {
        case 1:
            database = Database::administators;
            break;
        case 2:
            database = Database::employees;
            break;
        case 3:
            database = Database::waiters;
            break;
        case 4:
            database = Database::orders;
            break;
        case 5:
            database = Database::restaurants;
            break;
        default:
            cerr << "Invalid file number error!" << endl;
            database = Database::undefined;
            break;
    }
    return database;
}

string getDatabaseFile(Database database) {
    string fileName;

    switch (database) {
        case Database::administators:
            fileName = "administrators.txt";
            userActivity("User read from administrators.txt");
            break;
        case Database::employees:
            fileName = "employees.txt";
            userActivity("User read from employees.txt");
            break;
        case Database::waiters:
            fileName = "waiters.txt";
            userActivity("User read from waiters.txt");
            break;
        case Database::orders:
            fileName = "orders.txt";
            userActivity("User read from orders.txt");
            break;
        case Database::restaurants:
            fileName = "restaurant.txt";
            userActivity("User read from restaurants.txt");
            break;
        case Database::undefined:
            fileName = "";
            break;
    }
    return fileName;
}

Administrator createAdministrator() {
    string name;
    int age;
    string position;
    int salary;
    int entranceNumber;
    cout << "Please input administrator data : " << endl;
    cout << "Name: ";
    cin >> name;
    cout << endl;
    cout << "Age: ";
    cin >> age;
    cout << endl;
    cout << "Position: ";
    cin >> position;
    cout << endl;
    cout << "Salary: ";
    cin >> salary;
    cout << endl;
    cout << "Entrance number: ";
    cin >> entranceNumber;
    cout << endl;

    cout << "Administrator created" << endl;
    Administrator administrator{name, age, position, salary, entranceNumber};
    return administrator;
}

Employee createEmployee() {
    string name;
    int age;
    string position;
    int salary;
    cout << "Please input employee data : " << endl;
    cout << "Name: ";
    cin >> name;
    cout << endl;
    cout << "Age: ";
    cin >> age;
    cout << endl;
    cout << "Position: ";
    cin >> position;
    cout << endl;
    cout << "Salary: ";
    cin >> salary;
    cout << endl;

    cout << "Employee created" << endl;
    Employee employee{name, age, position, salary};
    return employee;
}

Waiter createWaiter() {
    string name;
    int age;
    string position;
    int salary;
    int floorNumber;
    Order order;
    cout << "Please input waiter data : " << endl;
    cout << "Name: ";
    cin >> name;
    cout << endl;
    cout << "Age: ";
    cin >> age;
    cout << endl;
    cout << "Position: ";
    cin >> position;
    cout << endl;
    cout << "Salary: ";
    cin >> salary;
    cout << endl;
    cout << "Floor number: ";
    cin >> floorNumber;
    cout << endl;
    cout << "Order: ";
    cin >> order;
    cout << endl;

    cout << "Waiter created" << endl;
    Waiter waiter{name, age, position, salary, floorNumber};
    return waiter;
}

Restaurant createRestaurant() {
    string title;
    string location;
    string status;

    cout << "Please input restaurant data : " << endl;
    cout << "Title: ";
    cin >> title;
    cout << endl;
    cout << "Location: ";
    cin >> location;
    cout << endl;
    cout << "Status: ";
    cin >> status;
    cout << endl;

    cout << "Restaurant created" << endl;
    Restaurant restaurant{title, location, status};
    return restaurant;
}

Order createOrder() {
    string items;
    int price;
    cout << "Please input order data : " << endl;
    cout << "Item: ";
    cin >> items;
    cout << endl;
    cout << "Price: ";
    cin >> price;
    cout << endl;

    cout << "Order created" << endl;
    Order order{items, price};
    return order;
}

void readFromFile() {
    cout << "Please select database for reading:" << endl;
    cout << "1. Administrator" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Waiter" << endl;
    cout << "4. Order" << endl;
    cout << "5. Restaurant" << endl;
    cout << "Please, select number of table" << endl;

    Database database = selectDatabase();

    if (database == Database::undefined) {
        throw std::invalid_argument("Invalid input type");
    }

    string fileName = getDatabaseFile(database);

    cout << "Reading from database..." << endl;

    ifstream read;
    read.open(fileName);
    try {
        if (!read.is_open()) {
            throw "File opening error!";
        }
        string buff;
        while (getline(read, buff)) {
            cout << buff << endl;
        }

        read.close();
    } catch(const char *ex){
        cerr << ex;
    }
    cout << "Reading from database finished." << endl;
}



void createAndWriteObject(Database database, ofstream &write) {
    switch (database) {
        case Database::administators:
            write << createAdministrator() << endl;
            userActivity("User wrote to administrators.txt");
            break;
        case Database::employees:
            write << createEmployee() << endl;
            userActivity("User wrote to employees.txt");
            break;
        case Database::waiters:
            write << createWaiter() << endl;
            userActivity("User wrote to waiters.txt");
            break;
        case Database::orders:
            write << createOrder() << endl;
            userActivity("User wrote to orders.txt");
            break;
        case Database::restaurants:
            write << createRestaurant() << endl;
            userActivity("User wrote to restaurants.txt");
            break;
    }
}

void writeToFile() {
    cout << "Please select database for writing:" << endl;
    cout << "1. Administrator" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Waiter" << endl;
    cout << "4. Order" << endl;
    cout << "5. Restaurant" << endl;
    cout << "Please, select number of table" << endl;

    Database database = selectDatabase();

    if (database == Database::undefined) {
        throw std::invalid_argument("Invalid input type");
    }
    string fileName = getDatabaseFile(database);

    cout << "Writing in database..." << endl;

    ofstream write;
    write.open(fileName, ios_base::app);

    if (!write.is_open()) {
        cerr << "File opening error!" << endl;
    } else {
        createAndWriteObject(database, write);
    }
    write.close();
    cout << "Writing in database finished." << endl;
}

void makeOrder(){
    userActivity("User ordered something");
    string fileName = "orders.txt";
    ofstream write;
    write.open(fileName, ios_base::app);

    if (!write.is_open()) {
        throw "File opening error!";
    } else {
        write << createOrder() << endl;
    }
    write.close();
}


int main() {
    //Login
    User usertype = login();

    //Program
    if (usertype == User::admin) {
        cout << "You logged in as admin. You can read and write from database" << endl;
        cout << "Please select action: read | write" << endl;
        userActivity("\n Admin logged in to app \n");
    } else {
        cout << "You logged in as user. You can read from database" << endl;
        cout << "Please select action: read | order" << endl;
        userActivity("\n User logged in to app \n");
    }

    string action;
    bool appIsActive = true;

    while (appIsActive) {
        cout << "Your action -> ";
        cin >> action;
        if (action == "read") {
            readFromFile();
            continue;
        } else if (action == "write" && usertype == User::admin) {
            writeToFile();
            continue;

        } else if (action == "write" && usertype == User::user) {
            cout << "You have no rights for writing database" << endl;

        } else if (action == "order" && usertype == User::user) {
            cout << "-*-* Please, make an order *-*-" << endl;
            makeOrder();
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

        } else if (action == "exit") {
            cout << "Exit..." << endl;
            appIsActive = false;
            break;

        } else {
            cout << "Incorrect action!" << endl;
            appIsActive = false;
            break;
        }
    }

    return 0;
}
