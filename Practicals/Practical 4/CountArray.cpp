#include "CountArray.h"

CountArray::CountArray(int** array,int* sizes,int baseSize) : TwoDArray(array,sizes,baseSize)
{
    
}

int* CountArray::operator[](int i)
{
    return &getSizes()[i];
}