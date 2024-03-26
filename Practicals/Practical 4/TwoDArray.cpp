#include "TwoDArray.h"

using namespace std;


TwoDArray::TwoDArray(int** array,int* sizes,int baseSize)
{
    this->baseSize = baseSize;
    this->sizes = new int[baseSize];
    this->array = new int*[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        this->sizes[i] = sizes[i];
    }
    
    for (int i = 0; i < baseSize; i++)
    {
        this->array[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            this->array[i][j] = array[i][j];
        }
        
    }
    
    
}

TwoDArray::~TwoDArray()
{
    delete[] sizes;
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete [] array;
    
}


ostream& operator<<(ostream& out,TwoDArray& t)
{
    for (int i = 0; i < t.baseSize; i++)
    {
        for (int j = 0; j < t.sizes[i]; j++)
        {
            if (j < t.sizes[i] - 1)
            {
                out << t.array[i][j] << " ";
            }
            else
            {
                out << t.array[i][j];
            }
            
            
        }
        out << endl;
    }
    return out;
}

int** TwoDArray::getArray()
{
    int** temp;
    temp = new int*[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            temp[i][j] = array[i][j];
        }
        
    }
    return temp;
}

int* TwoDArray::getSizes()
{
    int* temp = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = sizes[i];
    }
    return temp;
}

int TwoDArray::getBaseSize()
{
    return baseSize;
}

TwoDArray::operator int **(){
    int** temp;
    temp = new int*[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            temp[i][j] = array[i][j];
        }
        
    }
    return temp;
}

TwoDArray::operator int *(){
    int* temp = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = sizes[i];
    }
    return temp;
}

TwoDArray::operator int(){
    return baseSize;
}