#ifndef ISSmaller_H
#define ISSmaller_H
    #include <cstddef>
    #include "ValueDependantTester.h"

    class IsSmaller : public ValueDependantTester
    {
    private:
        static int numAliveObjects;
    public:
        IsSmaller(int value);
        ~IsSmaller();
        virtual bool evaluate(int val);
        virtual NumberTester* clone();
        static int getNumAliveObjects();

    };    


#endif