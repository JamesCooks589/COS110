//The base 2D array class

//# directives....
#ifndef TWODARRAY_H
#define TWODARRAY_H
//Do not add any more #includes
#include <iostream>
#include <string>

using namespace std; 
class TwoDArray;

ostream& operator<<(ostream&,TwoDArray&);

//Define class below
class TwoDArray
{
private:
    int** array;
    int* sizes;
    int baseSize;
protected:
    int** getArray();
    int* getSizes();
    int getBaseSize();
public:
    TwoDArray(int**,int*,int);
    ~TwoDArray();
    virtual int* operator[](int) = 0;
    operator int();
    operator int*();
    operator int**();
    friend ostream& operator<<(ostream&,TwoDArray&);
};

#endif