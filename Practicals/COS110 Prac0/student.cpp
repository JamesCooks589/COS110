#include <iostream>
#include <cstdlib>
#include "student.h"

using namespace std;

bool student::sayHello(){

    
}

string student::describe()
{
    string ID;
    ID = "ID101";
    double weight, ticketPrice;
    weight = 100;
    ticketPrice = 99;
    stringstream out;
    string sOut;
    out << ID << " <" << ticketPrice << "> (" << weight << ")";

    sOut = out.str();

    return sOut;

}

