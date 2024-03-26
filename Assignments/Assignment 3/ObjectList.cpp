#include "ObjectList.h"

using namespace std;


ObjectList::ObjectList(bool dim)
{
    dimension = dim;
    head = NULL;
    current = NULL;
}

void ObjectList::add(Object* obj)
{
    if (!head)
    {
        head = obj;
        current = obj;
    }
    else
    {      
        Object* itr = head;
        Object* prev = NULL;
        //find correct position
        while (itr && itr->getCoord(dimension) < obj->getCoord(dimension))
        {
            prev = itr;
            itr = itr->getNext(dimension);
        }
        //if first node
        if (prev == NULL)
        {
            head = obj;
            obj->setNext(itr, dimension);
            itr->setPrev(obj, dimension);
        }
        //anywhere else
        else
        {
            prev->setNext(obj, dimension);
            obj->setNext(itr, dimension);
            obj->setPrev(prev, dimension);
            //last element
            if (itr)
                itr->setPrev(obj, dimension);
        }
        
    }


}

Object* ObjectList::getHead()
{
    return head;
}

string ObjectList::print()
{
    if (head)
    {
        string output = "";
        current = head;
        while (current)
        {
            output += current->getIcon();
            current = current->getNext(dimension);
        }
        return output;
    }
    else
    {
        return "";
    }
    
}

void ObjectList::reset()
{
    if (head)
    {
        current = head;
    }
    else
    {
        current = NULL;
    }
    
    
}

Object* ObjectList::iterate()
{
    //return temp and set current to next
    if (current)
    {
        Object* tempCur = current;
        if (current->getNext(dimension))
        {
            current = current->getNext(dimension);
        }
        else
        {
            current = NULL;
            return NULL;
        }
        
        return tempCur;
    }
    else
    {
        return NULL;
    }
    
}

string ObjectList::debug()
{
    stringstream ssOut;
    ssOut << "Forward:\n";
    string Output = "";
    string aboveCheck = "";
    if (head)
    {
        current = head;
        //FORWARD
        while (current)
        {
            //if its the top node
            if (current->above)
            {
                aboveCheck = "N";
            }
            else
            {
                aboveCheck = "Y";
            }
            
            
            ssOut << "<" << current->getIcon() << "> at (" << current->getCoord(false) << "," << current->getCoord(true) << ") Top:" << aboveCheck << endl;
            current = current->getNext(dimension); 
        }
        //BACKWARDS
        while (current)
        {
            //if its the top node
           if (current->above)
            {
                aboveCheck = "N";
            }
            else
            {
                aboveCheck = "Y";
            }
            
            
            ssOut << "<" << current->getIcon() << "> at (" << current->getCoord(false) << "," << current->getCoord(true) << ") Top:" << aboveCheck << endl;
            current = current->getPrev(dimension); 
        }
        Output += ssOut.str();
        return Output;
        
    }
    else
    {
        return "";
    }
    
    
}
