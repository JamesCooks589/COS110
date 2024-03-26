#ifndef MINUS_CPP
#define MINUS_CPP
#include <cstddef>
#include "MinusOperator.h"
template<class T>
T MinusOperator<T>::operator()(T lhs, T rhs)
{
    return (lhs - rhs);
}

template<class T>
Operator<T>* MinusOperator<T>::clone()
{
    MinusOperator<T>* temp = new MinusOperator<T>();
    return temp;
}
#endif

