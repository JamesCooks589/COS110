#include "IsGreater.h"
  int IsGreater::numAliveObjects = 0;
IsGreater::IsGreater(int value) : ValueDependantTester(value)
{
    numAliveObjects++;
}

IsGreater::~IsGreater()
{
    numAliveObjects--;
}

bool IsGreater::evaluate(int val)
{
    if (val > value)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

NumberTester* IsGreater::clone()
{
    NumberTester* other = new IsGreater(value);

    return other;
}

int IsGreater::getNumAliveObjects()
{
    return IsGreater::numAliveObjects;
}
