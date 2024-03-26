#include "SortArray.h"


SortArray::SortArray(int** array,int* sizes,int baseSize) : TwoDArray(array,sizes,baseSize)
{
    
}

int* SortArray::operator[](int i)
{
    int* temp = new int[getSizes()[i]];
    int tempVal = 0;
    for (int j = 0; j < getSizes()[i]; j++)
    {
        temp[j] = getArray()[i][j];       
    }

    for (int a = 0; a < getSizes()[i]; a++)
    {
        for (int b = a + 1; b < getSizes()[i]; b++)
        {
            if (temp[a] > temp[b])
            {
                tempVal = temp[a];
                temp[a] = temp[b];
                temp[b] = tempVal;
            }
            
        }
        
    }
    
    
    return temp;
}
