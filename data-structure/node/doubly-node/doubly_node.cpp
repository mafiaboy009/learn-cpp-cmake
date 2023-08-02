#include "doubly_node.hpp"

template <typename T>
doubly_node<T>* doubly_node<T>::getNextNode()
{
    return _nextNode;
}

template <typename T>
doubly_node<T>* doubly_node<T>::getPrevNode()
{
    return _prevNode;
}

template <typename T>
void doubly_node<T>::setNextNode( doubly_node<T>* nextNode )
{
    _nextNode = nextNode;
}

template <typename T>
void doubly_node<T>::setPrevNode( doubly_node<T>* prevNode)
{
    _prevNode = prevNode;
}

template <typename T>
T doubly_node<T>::getData()
{
    return _data;
}