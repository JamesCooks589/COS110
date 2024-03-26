
#include "Object.h"

class Player : public Object
{
public:
    Player(int x, int y);
    void move(int x, int y);
};
