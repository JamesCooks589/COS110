#ifndef CALC_CPP
#define CALC_CPP
    #include "Calculator.h"
    #include <cstddef>
    template<class T>
    Calculator<T>::Calculator()
    {
        valueStack = new Stack<T>();
        operatorStack = new Stack<Operator<T>*>();
    }

    template<class T>
    Calculator<T>::~Calculator()
    {
        valueStack->~Stack();
        delete valueStack;
        operatorStack->~Stack();
        delete operatorStack;
    }

    template<class T>
    void Calculator<T>::addValue(T val)
    {
        valueStack->push(val);
    }

    template<class T>
    void Calculator<T>::addOperator(Operator<T>* op)
    {
        Operator<T>* newNode = op->clone();
        operatorStack->push(newNode);
    }

    template<class T>
    T Calculator<T>::removeValue()
    {
        if (valueStack->isEmpty())
        {
            return NULL;
        }
        else
        {
        valueStack->pop()->getData();
        }
    }

    template<class T>
    Operator<T>* Calculator<T>::removeOperator()
    {
        if (operatorStack->isEmpty())
        {
            return NULL;
        }
        else
        {
            return operatorStack->pop()->getData();
        }
        
        
        
    }

    template<class T>
    int Calculator<T>::numValues()
    {
       return valueStack->size();
    }

    template<class T>
    int Calculator<T>::numOperators()
    {
        return operatorStack->size();
    }

    template<class T>
    T Calculator<T>::calculate()
    {
        Node<T>* val1;
        Node<T>* val2;
        Node<Operator<T>*>* calc;
        Operator<T>* op;
        if (operatorStack->isEmpty())
        {
            return NULL;
        }
        
        while (operatorStack->size() != 0)
        {
            if (valueStack->size() < 2)
            {
                return NULL;
            }
            
            val1 = valueStack->pop();
            val2 = valueStack->pop();
            calc = operatorStack->pop();
            op = calc->getData();
            valueStack->push(op->operator()(val1->getData(),val2->getData()));
            
            
            
            
        }
        return valueStack->getTop()->getData();
    }
#endif

