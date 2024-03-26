#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"
#include <cstddef>
template<class T>
Stack<T>::Stack()
{
   top = NULL; 
}

template<class T>
Stack<T>::~Stack()
{
    if (top)
    {
        while (top)
        {
            this->pop();
        }
    }
    
}

template<class T>
void Stack<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);
   if (!top)
   {
     top = newNode;
   }
   else
   {
     newNode->setNext(top);
     top = newNode;
   }
   
    
}

template<class T>
Node<T>* Stack<T>::pop()
{
   Node<T>* ptr;
   if (!top)
   {
       return NULL;
   }
   else
   {
    ptr = top;
    top = top->getNext();
    return ptr;
   }
   
    
}

template<class T>
Node<T>* Stack<T>::getTop()
{
    return top;
}

template<class T>
int Stack<T>::size()
{
   Node<T>* ptr = top;
   int count = 0;
   if (!top)
   {
    return 0;
   }
   else
   {
     while (ptr)
     {
        count++;
        ptr = ptr->getNext();
     }
     return count;
   }
   
   
}

template<class T>
bool Stack<T>::isEmpty()
{
    if (!top)
    {
        return true;
    }
    return false;
    
}

template<class T>
Stack<T>* Stack<T>::reverse()
{
    Stack<T>* newStack = new Stack<T>();
    Node<T>* ptr = top;
    if (!top)
    {
        return newStack;
    }
    while (ptr)
    {
        newStack->push(ptr->getData());
        ptr=ptr->getNext();
    }
    return newStack;

    
    
}

template<class T>
bool Stack<T>::contains(T data)
{
    Node<T>* ptr;
    if (!top)
    {
        return false;
    }
    else
    {
        ptr = top;
        while (ptr)
        {
            if (ptr->getData() == data)
            {
                return true;
            }
            ptr = ptr->getNext();
        }
        return false;
    }
    
}
#endif

