#ifndef ISEVENODD_H
#define ISEVENODD_H
    #include <cstddef>
    #include "ValueIndependantTester.h"
    class IsEvenOdd : public ValueIndependantTester
    {
    private:
        static int numAliveObjects;
    public:
        IsEvenOdd();
        ~IsEvenOdd();
        virtual bool evaluate(int val);
        virtual NumberTester* clone();
        static int getNumAliveObjects();
    };
    
#endif