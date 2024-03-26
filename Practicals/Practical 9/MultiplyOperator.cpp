#ifndef MULTIPLY_CPP
#define MULTIPLY_CPP
#include "MultiplyOperator.h"
#include <cstddef>
template<class T>
T MultiplyOperator<T>::operator()(T lhs, T rhs)
{
    return (lhs * rhs);
}

template<class T>
Operator<T>* MultiplyOperator<T>::clone()
{
    MultiplyOperator<T>* temp = new MultiplyOperator<T>();
    return temp;
}
#endif

