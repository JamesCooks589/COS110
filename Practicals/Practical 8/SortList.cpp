#ifndef SORTLIST_CPP
#define SORTLIST_CPP
using namespace std;

#include <iostream>


template<class T>
SortList<T>::SortList(bool asc)
{
    ascending = asc;
    head = NULL;
    tail = NULL;
}

template<class T>
void SortList<T>::add(SortNode<T>* a)
{
    SortNode<T>* it = NULL;
    if (!head)
    {
        head = a;
    }
    else
    {
        it = head;
        while (it->next)
        {
            it = it->next;
        }
        it->next = a;
        a->prev = it;
    }
    
}

template<class T>
SortNode<T>* SortList<T>::remove(T val)
{
    SortNode<T>* nodePtr = head;
    SortNode<T>* prevNode = NULL;
    if (!head)
    {
        return NULL;
    }
    else
    {
        while (nodePtr)
        {
            if (nodePtr->getValue() == val)
            {
                if (prevNode == NULL)
                {
                    head = head->next;
                    nodePtr->next = NULL;
                    return nodePtr;
                }
                else
                {
                    prevNode->next = nodePtr->next;
                    nodePtr->next = NULL;
                    nodePtr->prev = NULL;
                    return nodePtr;
                }
                
                
            }
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        return NULL;
        
    }
    
    
    
    
}

template<class T>
void SortList<T>::sort()
{
    bool AoD = ascending;
    if (head == NULL)//list empty
    {
        return;
    }
    else
    {
        SortList<T>* temp = new SortList<T>(AoD);
        while (head != NULL)
        {
            SortNode<T>* iterator = head;
            SortNode<T>* toSwap = head;
            while (iterator != NULL)
            {
                if (!AoD)
                {
                    if (iterator->getValue() > toSwap->getValue())
                    {
                        toSwap = iterator;
                    }
                    
                }
                if (AoD)
                {
                    if (iterator->getValue() < toSwap->getValue())
                    {
                        toSwap = iterator;
                    }
                }
                
              iterator = iterator->next;  
            }
            SortNode<T>* tNode = this->remove(toSwap->getValue());
            temp->add(tNode);
        }
        this->head = temp->head;
        this->tail = temp->tail;
        
    }
    
       
    
}

template<class T>
string SortList<T>::print()
{
    SortNode<T>* nodePtr = head;
    string output;
    while (nodePtr)
    {
        if (nodePtr->next)
        {
            output += nodePtr->print() + ",";
        }
        else
        {
            output += nodePtr->print();
        }
        
        
        nodePtr = nodePtr->next;
    }
    return output;
}

template<class T>
SortNode<T>* SortList<T>::getHead()
{
    return head;
}

template<class T>
void SortList<T>::setAsc(bool a)
{
   ascending =  a;
   this->sort();
}

template<class T>
string SortList<T>::debug()
{
    return "testing purposes";
}

#endif