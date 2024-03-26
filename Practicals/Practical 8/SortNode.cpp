#ifndef SORTNODE_CPP
#define SORTNODE_CPP
using namespace std;


template<class T>
SortNode<T>::SortNode(T val)
{
    value = val;
    next = NULL;
    prev = NULL;
}

template<class T>
string SortNode<T>::print()
{
    string temp;
    stringstream ss;
    ss << value;
    ss >> temp;
    return temp;
}

template<class T>
T SortNode<T>::getValue()
{
    return value;
}

#endif