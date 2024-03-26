//The Passenger implementation file
#include "Passenger.h"
using namespace std;
Passenger::Passenger(string id, double w, double t)
{
    ID = id;
    weight = w;
    ticketPrice = t;
}

string Passenger::describe()
{
    stringstream out,out2;
    string sOut, sTicket, sWeight;
    out << ticketPrice;
    out >> sTicket;
    out2 << weight;
    out2 >> sWeight;

    sOut = ID + " <" + sTicket + "> (" + sWeight + ")";

    return sOut;
}

double Passenger::getWeight() const
{
    return weight;
}

double Passenger::getValue() const
{
   return ticketPrice; 
}
