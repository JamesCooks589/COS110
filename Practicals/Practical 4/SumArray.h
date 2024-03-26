#ifndef SUMARRAY_H
#define SUMARRAY_H

#include "TwoDArray.h"

class SumArray : public TwoDArray
{
public:
    SumArray(int**,int*,int);
    virtual int* operator[](int);
};




#endif