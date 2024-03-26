#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests)
{
    if (maxNumTests < 0)
    {
        maxNumTesters = 0;
        currNumTesters = 0;
        testers = new NumberTester*[0];
    }
    else
    {
        this->maxNumTesters = maxNumTests;
        currNumTesters = 0;
        testers = new NumberTester*[maxNumTests];
        for (int i = 0; i < maxNumTests; i++)
        {
            testers[i] = NULL;
        }
        
    }
    
}

TesterInterface::TesterInterface(TesterInterface* other)
{
    if (!other)
    {
        maxNumTesters = 0;
        currNumTesters = 0;
        testers = new NumberTester*[0];
    }
    else
    {
        maxNumTesters = other->maxNumTesters;
        currNumTesters = other->currNumTesters;
        testers = new NumberTester*[maxNumTesters];
        for (int i = 0; i < maxNumTesters; i++)
        {   
            if (other->testers[i])
            {
               testers[i] = other->testers[i]->clone();
            }
            else
            {
                testers[i] = NULL;
            }
            
            
        }
        
    }
    
    
}

TesterInterface::TesterInterface(TesterInterface& other)
{
    maxNumTesters = other.maxNumTesters;
    currNumTesters = other.currNumTesters;
    testers = new NumberTester*[maxNumTesters];
        for (int i = 0; i < maxNumTesters; i++)
        {
            if (other.testers[i])
            {
               testers[i] = other.testers[i]->clone();
            }
            else
            {
                testers[i] = NULL;
            }
        }
}

TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            delete testers[i];
        }
        
    }
    delete[] testers;
}

int TesterInterface::addTester(NumberTester* tester)
{
    if (!tester || currNumTesters == maxNumTesters)
    {
        return -1;
    }

    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] == NULL)
        {
            testers[i] = tester->clone();
            currNumTesters++;
            return i;
        }
        
    }
    
    return -1;
    
}

bool TesterInterface::removeTester(int pos)
{
    if (pos < 0 || pos > maxNumTesters || testers[pos] == NULL)
    {
        return false;
    }

    currNumTesters--;
    delete testers[pos];
    testers[pos] = NULL;

    return true;
    
}

bool TesterInterface::evaluate(int num)
{
    if (currNumTesters == 0)
    {
        return false;
    }

    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            if (testers[i]->evaluate(num) == false)
            {
                return false;
            }
            
        }
        
    }
    
    return true;
    
}

int* TesterInterface::failedTests(int num)
{

    int count = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            if (testers[i]->evaluate(num) == false)
            {
                count++;
            }
            
        }
        
    }

    if (count == 0 || currNumTesters == 0)
    {
        int* arr = new int[0];
        return arr;
    }
    
    int a = 0;
    int* arr = new int[count];
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            if (testers[i]->evaluate(num) == false)
            {
                arr[a] = i;
                a++;
            }
            
        }
        
    }

    return arr;

}

int TesterInterface::numberOfFailedTests(int num)
{
     int count = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            if (testers[i]->evaluate(num) == false)
            {
                count++;
            }
            
        }
        
    }

    return count;
}

int TesterInterface::getCurrNumTesters() const
{
    return currNumTesters;
}

int TesterInterface::getMaxNumTesters() const
{
    return maxNumTesters;
}

NumberTester* TesterInterface::operator[](int pos)
{
    if (pos < 0 || pos > maxNumTesters)
    {
        return NULL;
    }
    
    return testers[pos];
}
