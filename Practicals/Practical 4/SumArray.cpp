#include "SumArray.h";


SumArray::SumArray(int** array,int* sizes,int baseSize) : TwoDArray(array,sizes,baseSize)
{
    
}

int* SumArray::operator[](int i)
{
    int val = 0;

    for (int j = 0; j < getSizes()[i]; j++)
    {
        val += getArray()[i][j];
    }
    
    int* total = new int(val);
    return total;
}
