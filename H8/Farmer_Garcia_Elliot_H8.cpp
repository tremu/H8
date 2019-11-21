/*
Program No.         : Farmer_Garcia_Elliot_H7.cpp
Programmer          : Elliot Farmer Garcia
Course / Section    : ELET 2300 - 07 / 23493
Instructor          : Dr. F. Attarzadeh
Date Assigned       : 11/21/2019
Date Modified       : 11/21/2019
Due Date            : 12/05/2019
Compiler            : Microsoft Visual Studio Enterprise 2019
Environment         : Console Applications
Operating System    : Windows 7
*/

/*
Problem Statement

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int createc(string f, string d);
int createmyCar(string make, string model, string carf);
int printCar(string make, string model, string carf);

int main() {

    //get filename for make
    string makef;
    cout << "Please enter filename for make (.txt will be appended): ";
    cin >> makef;
    makef.append(".txt");    //append '.txt'

    //get make
    cin.ignore();
    string make;
    cout << "Please enter make: ";
    getline(cin, make);

    //write make to c1.txt, quit if unsuccessful
    if (createc(makef, make)) {

        cout << "Unable to open file";
        return 1;

    }

    //get filename for model
    string modelf;
    cout << "Please enter filename for model (.txt will be appended): ";
    cin >> modelf;
    modelf.append(".txt");   //append '.txt'

    //get model
    cin.ignore();
    string model;
    cout << "Please enter model: ";
    getline(cin, model);

    //write model to c2.txt, quit if unsuccessful
    if (createc(modelf, model)) {

        cerr << "Unable to open file";
        return 1;

    }

    //get filename for myCar
    string carf;
    cout << "Please enter filename for car (.txt will be appended): ";
    cin >> carf;
    carf.append(".txt");   //append '.txt'

    //write make and model to myCar.txt, quit if unsuccessful
    if (createmyCar(makef, modelf, carf)) {

        cerr << "Unable to open file";
        return 1;

    }

    //read and print contents of c1, c2, and myCar
    if (printCar(makef, modelf, carf)) {

        cerr << "Unable to open file";
        return 1;

    }

    return 0;

}

int createc(string f, string d) {

    ofstream c(f, ios::out | ios::trunc);

    if (!c.is_open()) {

        return 1;

    }

    c << d;
    c.close();

    return 0;

}

int createmyCar(string makef, string modelf, string carf) {

    //string "make model" read from c1 and c2
    string car = "";

    //string for reading from c1 and c2
    string buffer;

    //open c1 for reading
    ifstream c1(makef, ios::in);

    //throw error if c1 fails to open
    if (!c1.is_open()) {

        return 1;

    }

    //read c1 into buffer and close
    getline(c1, buffer);
    c1.close();

    //add make to car
    car.append(buffer);
    car.append(" ");

    ifstream c2(modelf, ios::in);

    if (!c2.is_open()) {

        return 1;

    }

    getline(c2, buffer);
    c2.close();

    car.append(buffer);

    ofstream myCar(carf, ios::out | ios::trunc);

    if (!myCar.is_open()) {

        return 1;

    }

    myCar << car;
    myCar.close();

    return 0;

}

int printCar(string makef, string modelf, string carf) {

    string buffer;

    cout << "\n\n";
    cout << makef << "\t\t\t";

    ifstream c1(makef, ios::in);

    if (!c1.is_open()) {

        return 1;

    }

    getline(c1, buffer);
    c1.close();

    cout << buffer << "\n";

    cout << modelf << "\t\t\t";

    ifstream c2(modelf, ios::in);

    if (!c2.is_open()) {

        return 1;

    }

    getline(c2, buffer);
    c2.close();

    cout << buffer << "\n";

    cout << carf << "\t\t";

    ifstream myCar(carf, ios::in);

    if (!myCar.is_open()) {

        return 1;

    }

    getline(myCar, buffer);
    myCar.close();

    cout << buffer << "\n";

    return 0;
}