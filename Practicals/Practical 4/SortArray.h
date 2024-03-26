#ifndef SORTARRAY_H
#define SORTARRAY_H

#include "TwoDArray.h"

class SortArray : public TwoDArray
{
public:
    SortArray(int**,int*,int);
    virtual int* operator[](int);
};



#endif