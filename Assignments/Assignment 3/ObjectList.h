
#include "Object.h"
#include <string>

class ObjectList
{
private:
    bool dimension;
    Object* head;
    Object* current;
public:
    ObjectList(bool dim);
    void add(Object* obj);
    Object* getHead();
    string print();
    void reset();
    Object* iterate();
    string debug();
};
