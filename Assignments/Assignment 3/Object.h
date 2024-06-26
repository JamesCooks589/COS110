
#include <sstream>

class Object
{
protected:
    char icon;
    int xPos;
    int yPos;
public:
    Object(int x, int y);
    Object* nextHoriz;
    Object* nextVert;
    Object* prevHoriz;
    Object* prevVert;
    Object* above;
    Object* below;
    char getIcon();
    int getCoord(bool dimension);
    Object* getNext(bool dimension);
    Object* getPrev(bool dimension);
    void setNext(Object* obj, bool dim);
    void setPrev(Object* obj, bool dim);
};
