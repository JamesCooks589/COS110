#include "IsSmaller.h"

    int IsSmaller::numAliveObjects = 0;
IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{
    numAliveObjects++;
}

IsSmaller::~IsSmaller()
{
   numAliveObjects--; 
}

bool IsSmaller::evaluate(int val)
{
    if (val < value)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

NumberTester* IsSmaller::clone()
{
   NumberTester* other = new IsSmaller(value);

    return other; 
}

int IsSmaller::getNumAliveObjects()
{
    return IsSmaller::numAliveObjects;
}
