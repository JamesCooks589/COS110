#ifndef COUNTARRAY_H
#define COUNTARRAY_H

#include "TwoDArray.h"

class CountArray : public TwoDArray
{
public:
    CountArray(int**,int*,int);
    virtual int* operator[](int);
};



#endif