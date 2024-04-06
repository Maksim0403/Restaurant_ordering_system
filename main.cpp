#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
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

enum class User{
    user, admin, undefined
};

enum class Action{
    read, write
};

void outputInfoOnUI(const Printable &obj);
void outputAmountOfEmployees(const Employee &employee);

int main() {
    Administrator administrator1{"Ivan", 34, "Administrator", 3000, 2};
    Waiter waiter1{"Petro", 23, "Waiter", 1200, 3};

    string username;
    User usertype = User::undefined;

    cout << "*-*-*-*-*-*-*-Login-*-*-*-*-*-*-*" << endl;
    cout << "Input username: " << endl;
    cin >> username;

    if(username == "admin"){
        string password;
        cout << "Input password: " << endl;
        cin >> password;

        if(password == "admin"){
            usertype = User::admin;
        } else {
            cout << "Incorrect credentials!" << endl;
        }
    } else {
        usertype = User::user;
    }

    cout << "Login successful!" << endl;

    if(usertype == User::admin){
        cout << "You logged in as admin. You can read and write from database" << endl;
        cout << "Please select action: read | write" << endl;
    } else {
        cout << "You logged in as user. You can read from database" << endl;
        cout << "Please select action: read" << endl;
    }

    string action;
    bool appIsActive = true;
    string path = "database.txt";

    while (appIsActive) {
        cout << "Your action -> ";
        cin >> action;
        if(action == "read"){
            cout << "Reading from database..." << endl;

            ifstream read;
            read.open(path);

            if(!read.is_open()){
                cerr << "File opening error!" << endl;
            }
            while (read.is_open()){
                string strInput;

                getline(read, strInput);
                cout << strInput << endl;

                break;
            }
            continue;

            read.close();

        } else if(action == "write" && usertype == User::admin){
            cout << "Writing in database..." << endl;

            ofstream write;
            write.open(path);

            if(!write.is_open()){
                cerr << "File opening error!" << endl;
            } else {
                write << administrator1 << endl;
                write << waiter1 << endl;
            }
            continue;
            write.close();

        } else if(action == "write" && usertype == User::user){
            cout << "You have no rights for writing database" << endl;

        } else if(action == "exit"){
            cout << "Exit..." << endl;
            appIsActive = false;
            break;

        } else {
            cout << "Incorrect action!" << endl;
            appIsActive = false;
            break;
        }
        return 0;
    }

    /*
     * vector<Worker> readWorkersFromFile(string fileName) {
    string buff;
    ifstream fin;
    fin.open(fileName);
    vector<Worker> result;
    if (!fin.is_open()) {
        cout << "File cannot be open!\n";
    }
    while (getline(fin, buff)) {
        vector<string> v = split(buff, ',');
        //stoi converts string to int
        Worker worker = {stoi(v[0]), v[1], stoi(v[2]), v[3], v[4], stoi(v[5]), stoi(v[6])};
        result.push_back(worker);
    }
    fin.close();
    return result;
}

void writeWorkersToFile(string fileName, Worker listOfWorkers[], int arraySize) {
    ofstream file(fileName);
    for (int i = 0; i < arraySize; i++) {
        file << convertWorkerToString(listOfWorkers[i]) << endl;
    }
    file.close();
}*/





    /*Restaurant rest1{"Aristocrat", "Holovna", "Opened"};
    Restaurant rest2{"Lavanda"};
    Restaurant rest3{rest1};

    cout<<rest1;
    cout<<rest2;
    cout<<rest3;

    Order menu{"Salad ", 220};
    Order menu1{"Fries ", 320};
    Order menu2 {"Steak ", 280};
    //Order menu3;
    Order otherMenu(menu);
    //Order orderPlus = menu1 + menu;

    //cout<<orderPlus;
    cout<<menu;
    cout<<menu1;
    cout<<otherMenu;
    cout<<menu2;

    Waiter waiter1{"Petro", 23, "Waiter", 1200, 3, menu1};
    Waiter waiter2{"John", 21, "Waiter", 1000, 1, menu2};
    Employee *waiter3 = new Waiter();

    waiter3->setName(string("Michael"));
    waiter3->setSalary(2000);

    Waiter waiter4{};
    Waiter &waiterRef = waiter4;
    waiterRef.setName(string ("Alex"));
    waiterRef.setAge(23);
    waiterRef.setSalary(750);
    waiterRef.Waiter::setFloorNumber(2);
    
    Administrator administrator1{"Ivan", 34, "Administrator", 3000, 2};
    Administrator administrator2{"Frank", 31, "Administrator", 2500, 1};

    outputInfoOnUI(waiter1);
    outputInfoOnUI(waiter2);
    outputInfoOnUI(*waiter3);
    outputInfoOnUI(waiter4);
    outputInfoOnUI(administrator1);
    outputInfoOnUI(administrator2);
    outputAmountOfEmployees(waiter1);
    outputAmountOfEmployees(administrator1);
    outputInfoOnUI(rest1);
    outputInfoOnUI(menu1);

*//*
    cin>>menu3;
    cout<<menu3;*/
    return 0;
}

void outputInfoOnUI(const Printable &obj){
    cout<<"-------------------------------------"<<endl;
    cout<<obj;
    cout<<"-------------------------------------"<<endl;
  }

void outputAmountOfEmployees(const Employee &employee){
    cout<<"-------------------------------------"<<endl;
    employee.outputAmountOfEmployees();
    cout<<"-------------------------------------"<<endl;

}