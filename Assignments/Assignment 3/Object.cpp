#include "Object.h"

using namespace std;

Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    nextHoriz = NULL;
    nextVert = NULL; 
    prevHoriz = NULL;
    prevVert = NULL;
    above = NULL;
    below = NULL;
    icon = '?';
}

char Object::getIcon()
{
    Object* ptr = above;
    if (above == NULL)
    {
        return icon;
    }
    else
    {       
        while (ptr)
        {
            ptr = ptr->above;
        }
        return ptr->icon;
    }

    
}

int Object::getCoord(bool dimension)
{
    if (dimension == false)
    {
        return xPos;
    }
    else
    {
        return yPos;
    }
    
    
}

Object* Object::getNext(bool dimension)
{
    if (dimension == false)
    {
        return nextHoriz;
    }
    else
    {
        return nextVert;
    }
}

Object* Object::getPrev(bool dimension)
{
    if (dimension == false)
    {
        return prevHoriz;
    }
    else
    {
        return prevVert;
    }
}

void Object::setNext(Object* obj, bool dim)
{
    if (dim == false)
    {
        nextHoriz = obj;
    }
    else
    {
        nextVert = obj;
    }
    
    
}

void Object::setPrev(Object* obj, bool dim)
{
    if (dim == false)
    {
        prevHoriz = obj;
    }
    else
    {
        prevVert = obj;
    }
}
