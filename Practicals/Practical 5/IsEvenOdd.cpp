#include "IsEvenOdd.h"

int IsEvenOdd::numAliveObjects = 0;
IsEvenOdd::IsEvenOdd()
{
    numAliveObjects++;
}

IsEvenOdd::~IsEvenOdd()
{
    numAliveObjects--;
}

bool IsEvenOdd::evaluate(int val)
{
    if (val % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

NumberTester* IsEvenOdd::clone()
{
     NumberTester* other = new IsEvenOdd();

    return other;
}

int IsEvenOdd::getNumAliveObjects()
{
    return IsEvenOdd::numAliveObjects;
}
