//The Cargo implementation file
#include "Cargo.h"

using namespace std;
Cargo::Cargo(double w, double ppw)
{
    weight = w;
    value = w * ppw;
}

string Cargo::describe()
{
    stringstream out, out2;
    string sOut, sVal, sW;
    out << value;
    out >> sVal;
    out2 << weight;
    out2 >> sW;

    sOut = "Generic cargo <" + sVal + "> (" + sW + ")";

    return sOut;
}

double Cargo::getWeight() const
{
   return weight; 
}

double Cargo::getValue() const
{
    return value;
}
