//The Plane class
#ifndef PLANE_H
#define PLANE_H
#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"
#include <string>

//See spec on inclusion strategy for templates
using namespace std;
template <class T>
class Plane
{
private:
    vector<T*> cargo;
    double maxWeight;
public:
    Plane(double);
    ~Plane();
    void add(T*);
    void remove(T*);
    double calculateValue();
    string getDescription();
};

#include "Plane.cpp"
#endif