//The Cargo class
#ifndef cargo_h
#define cargo_h
#include <string>
#include <sstream>
using namespace std;
class Cargo
{
private:
    double weight;
    double value;
public:
    Cargo(double, double);
    string describe();
    double getWeight() const;
    double getValue() const;
};



#endif