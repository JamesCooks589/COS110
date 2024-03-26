#ifndef ISGreater_H
#define ISGreater_H
    #include <cstddef>
    #include "ValueDependantTester.h"

    class IsGreater : public ValueDependantTester
    {
    private:
        static int numAliveObjects;
    public:
        IsGreater(int value);
        ~IsGreater();
        virtual bool evaluate(int val);
        virtual NumberTester* clone();
        static int getNumAliveObjects();

    };    

  
#endif