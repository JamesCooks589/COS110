#ifndef ISPrimeNumber_H
#define ISPrimeNumber_H
    #include <cstddef>
    #include "ValueIndependantTester.h"
    class IsPrimeNumber : public ValueIndependantTester
    {
    private:
        static int numAliveObjects;
    public:
        IsPrimeNumber();
        ~IsPrimeNumber();
        virtual bool evaluate(int val);
        virtual NumberTester* clone();
        static int getNumAliveObjects();
    };
   
    
    
#endif