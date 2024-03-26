
#include "ObjectList.h"
#include <string>

class Map
{
private:
   int width;
   int height;
   ObjectList** rows;
   ObjectList** columns;
public:
    Map(int w, int h);
    ~Map();
    void add(Object* obj);
    string print();
};
