#ifndef PLUS_CPP
#define PLUS_CPP
#include "PlusOperator.h"
#include <cstddef>
template<class T>
T PlusOperator<T>::operator()(T lhs, T rhs)
{
   return (lhs + rhs); 
}

template<class T>
Operator<T>* PlusOperator<T>::clone()
{
    PlusOperator<T>* temp = new PlusOperator<T>();
    return temp;
}
#endif

