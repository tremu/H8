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

This program writes the make of the user's car to a specified file, writes
the model of the user's car to a specified file, writes the make and model
to a third specified file, then reads and prints the title and contents
of all of the above files.

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string getinput(string out, int file = 0);
int createc(string f, string d);
int createmyCar(string makef, string modelf, string carf);
int printCar(string makef, string modelf, string carf);

int main() {

    //get filenames and data for make, model, and myCar
    string makef = getinput("Please enter filename for make", 1);
    string make = getinput("Please enter make");
    string modelf = getinput("Please enter filename for model", 1);
    string model = getinput("Please enter model");
    string carf = getinput("Please enter filename for car", 1);

    //read and write files, quit if unsuccessful
    if (createc(makef, make) | createc(modelf, model) 
        | createmyCar(makef, modelf, carf) | printCar(makef, modelf, carf)) {

        cerr << "Unable to open file";
        return 1;

    }

    system("pause");
    return 0;

}

//gets filenames and data from user
string getinput(string out, int file) {

    //string to be acquired from user
    string s;

    //print prompt from provided argument
    cout << out;
    if (file)
        cout << " (.txt will be appended)";
    cout << ": ";

    //write cin to s
    getline(cin, s);

    //append .txt if s is a filename
    if (file)
        s.append(".txt");

    return s;

}

int createc(string f, string d) {

    //open new file c for writing
    ofstream c(f, ios::out | ios::trunc);

    //throw error if file fails to open
    if (!c.is_open())
        return 1;

    //write d to file
    c << d;

    //close file
    c.close();

    return 0;

}

int createmyCar(string makef, string modelf, string carf) {

    //open files for reading or writing
    ifstream c1(makef, ios::in);
    ifstream c2(modelf, ios::in);
    ofstream myCar(carf, ios::out | ios::trunc);

    //throw error if any files fail to open
    if (!c1.is_open() | !c2.is_open() | !myCar.is_open())
        return 1;


    //string "make model" read from c1 and c2
    string car = "";

    //string for reading from c1 and c2
    string buffer;

    //read c1 into buffer, append to car
    getline(c1, buffer);
    car.append(buffer);
    car.append(" ");

    //read c2 into buffer, append to car
    getline(c2, buffer);
    car.append(buffer);

    //write car to myCar
    myCar << car;

    //close files
    c1.close();
    c2.close();
    myCar.close();

    return 0;

}

int printCar(string makef, string modelf, string carf) {

    //open files for reading
    ifstream c1(makef, ios::in);
    ifstream c2(modelf, ios::in);
    ifstream myCar(carf, ios::in);

    //throw error if any files fail to open
    if (!c1.is_open() | !c2.is_open() | !myCar.is_open())
        return 1;

    //string for reading from files
    string buffer;

    cout << "\n";

    //write table of filenames and file contents
    //make
    cout << makef << "\t\t\t";
    getline(c1, buffer);
    cout << buffer << "\n";

    //model
    cout << modelf << "\t\t\t";
    getline(c2, buffer);
    cout << buffer << "\n";

    //car
    cout << carf << "\t\t";
    getline(myCar, buffer);
    cout << buffer << "\n\n";

    //close files
    c1.close();
    c2.close();
    myCar.close();

    return 0;
}